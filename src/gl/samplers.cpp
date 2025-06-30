#include "samplers.h"

#include "../glx/hardext.h"
#include "blit.h"
#include "debug.h"
#include "fpe.h"
#include "gl4es.h"
#include "glstate.h"
#include "init.h"
#include "loader.h"
#include "texture.h"
#include "../../include/khash.h"

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif

KHASH_MAP_IMPL_INT(samplerlist_t, glsampler_t *);

GLuint new_sampler(GLuint base) {
    khint_t k;
    khash_t(samplerlist_t) *list = glstate->samplers.samplerlist;
    while(1) {
        k = kh_get(samplerlist_t, list, base);
        if (k == kh_end(list))
            return base;
        ++base;
    }
}

glsampler_t* find_sampler(GLuint sampler) {
    khint_t k;
    khash_t(samplerlist_t) *list = glstate->samplers.samplerlist;
    k = kh_get(samplerlist_t, list, sampler);

    if (k != kh_end(list)){
        return kh_value(list, k);
    }
    return nullptr;
}

void del_sampler(GLuint sampler) {
    khint_t k;
    khash_t(samplerlist_t) *list = glstate->samplers.samplerlist;
    k = kh_get(samplerlist_t, list, sampler);
    glsampler_t* s = nullptr;
    if (k != kh_end(list)){
        s = kh_value(list, k);
        kh_del(samplerlist_t, list, k);
    }
    if(s) {
        for (int i=0; i<MAX_TEX; ++i)
            if(glstate->samplers.sampler[i]==s)
                glstate->samplers.sampler[i] = nullptr;
        LOAD_GLES(glDeleteSamplers);
        GLuint gles_id = s->glname;
        gles_glDeleteSamplers(1, &gles_id);
        free(s);
    }
}

void init_sampler(glsampler_t* sampler)
{
    memset(sampler, 0, sizeof(glsampler_t));
    sampler->min_filter = GL_NEAREST_MIPMAP_LINEAR;
    sampler->mag_filter = GL_LINEAR;
    sampler->wrap_s = sampler->wrap_t = (globals4es.defaultwrap?0:GL_REPEAT);
    sampler->min_lod = -1000.f;
    sampler->max_lod = 1000.f;
}

void gl4es_glGenSamplers(GLsizei n, GLuint *ids)
{
    DBG(SHUT_LOGD("glGenSamplers(%i, %p)\n", n, ids);)
    FLUSH_BEGINEND;
    noerrorShim();
    if (n<1) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    LOAD_GLES(glGenSamplers);
    gles_glGenSamplers(n, ids);
    int ret;
    khint_t k;
    khash_t(samplerlist_t) *list = glstate->samplers.samplerlist;
    for(int i=0; i<n; ++i) {
        k = kh_put(samplerlist_t, list, ids[i], &ret);
        glsampler_t *sampler = kh_value(list, k) = malloc(sizeof(glsampler_t));
        init_sampler(sampler);
        sampler->glname = ids[i];
        LOAD_GLES(glSamplerParameteri);
        LOAD_GLES(glSamplerParameterf);
        gles_glSamplerParameteri(ids[i], GL_TEXTURE_MIN_FILTER, sampler->min_filter);
        gles_glSamplerParameteri(ids[i], GL_TEXTURE_MAG_FILTER, sampler->mag_filter);
        gles_glSamplerParameteri(ids[i], GL_TEXTURE_WRAP_S, sampler->wrap_s);
        gles_glSamplerParameteri(ids[i], GL_TEXTURE_WRAP_T, sampler->wrap_t);
        gles_glSamplerParameterf(ids[i], GL_TEXTURE_MIN_LOD, sampler->min_lod);
        gles_glSamplerParameterf(ids[i], GL_TEXTURE_MAX_LOD, sampler->max_lod);
    }
}

void gl4es_glBindSampler(GLuint unit, GLuint sampler)
{
    DBG(SHUT_LOGD("gl4es_glBindSampler(%u, %u)\n", unit, sampler);)
    if(unit>hardext.maxtex) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glsampler_t *s = find_sampler(sampler);
    if(!s && sampler) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    noerrorShim();
    glstate->samplers.sampler[unit] = s;
    LOAD_GLES(glBindSampler);
    if (s)
        gles_glBindSampler(unit, s->glname);
    else
        gles_glBindSampler(unit, 0);
    if(glstate->bound_changed<unit+1)
        glstate->bound_changed = unit+1;
}

void gl4es_glDeleteSamplers(GLsizei n, const GLuint* samplers)
{
    DBG(SHUT_LOGD("glDeleteSamplers(%i, %p)\n", n, samplers);)
    if(n<0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    noerrorShim();
    if(!n)
        return;
    for(int i=0; i<n; ++i)
        del_sampler(samplers[i]);
}

GLboolean gl4es_glIsSampler(GLuint id)
{
    DBG(SHUT_LOGD("glIsSampler(%u)\n", id);)
    glsampler_t *s = find_sampler(id);
    if(s)
        return GL_TRUE;
    return GL_FALSE;
}

int samplerParameterfv(glsampler_t* sampler, GLenum pname, const GLfloat *params)
{
    DBG(SHUT_LOGD("samplerParameterfv(%p(%d), %s, [%f(%s)...])\n", sampler, sampler->glname, PrintEnum(pname), params[0], PrintEnum(params[0]));)
    GLint param = *params;
    switch(pname) {
        case GL_TEXTURE_MIN_FILTER:
            switch(param) {
                case GL_NEAREST:
                case GL_LINEAR:
                case GL_NEAREST_MIPMAP_NEAREST:
                case GL_LINEAR_MIPMAP_NEAREST:
                case GL_NEAREST_MIPMAP_LINEAR:
                case GL_LINEAR_MIPMAP_LINEAR:
                    sampler->min_filter = param;
                    break;
                default:
                    errorShim(GL_INVALID_ENUM);
                    return 1;
            }
            break;
        case GL_TEXTURE_MAG_FILTER:
            switch(param) {
                case GL_NEAREST:
                case GL_LINEAR:
                    sampler->mag_filter = param;
                    break;
                default:
                    errorShim(GL_INVALID_ENUM);
                    return 1;
            }
            break;
        case GL_TEXTURE_MIN_LOD:
            sampler->min_lod = *params;
            break;
        case GL_TEXTURE_MAX_LOD:
            sampler->max_lod = *params;
            break;
        case GL_TEXTURE_WRAP_S:
        case GL_TEXTURE_WRAP_T:
        case GL_TEXTURE_WRAP_R:
            switch (param) {
                case GL_CLAMP:
                case GL_CLAMP_TO_BORDER:
                case GL_CLAMP_TO_EDGE:
                case GL_REPEAT:
                case GL_MIRRORED_REPEAT_OES:
                    break;
                default:
                    errorShim(GL_INVALID_ENUM);
                    return 1;
            }
            if(pname==GL_TEXTURE_WRAP_S) sampler->wrap_s = param;
            if(pname==GL_TEXTURE_WRAP_T) sampler->wrap_t = param;
            if(pname==GL_TEXTURE_WRAP_R) sampler->wrap_r = param;
            break;
        case GL_TEXTURE_COMPARE_MODE:
            switch(param) {
                case GL_COMPARE_REF_TO_TEXTURE:
                case GL_NONE:
                    break;
                default:
                    errorShim(GL_INVALID_ENUM);
                    return 1;
            }
            sampler->compare = param;
            break;
        case GL_TEXTURE_COMPARE_FUNC:
            switch(param) {
                case GL_LEQUAL:
                case GL_GEQUAL:
                case GL_LESS:
                case GL_GREATER:
                case GL_EQUAL:
                case GL_NOTEQUAL:
                case GL_ALWAYS:
                case GL_NEVER:
                    break;
                default:
                    errorShim(GL_INVALID_ENUM);
                    return 1;
            }
            sampler->func = param;
            break;
        case GL_TEXTURE_BORDER_COLOR:
            memcpy(sampler->border_color, params, 4*sizeof(GLfloat));
            break;
        default:
            return 0;
    }
    noerrorShim();
    return 1;
}

int getSamplerParameterfv(glsampler_t* sampler, GLenum pname, GLfloat *params)
{
    DBG(SHUT_LOGD("samplerParameterfv(%p(%d), %s, %p)\n", sampler, sampler->glname, PrintEnum(pname), params);)
    switch(pname) {
        case GL_TEXTURE_MIN_FILTER:
            *params = sampler->min_filter;
            break;
        case GL_TEXTURE_MAG_FILTER:
            *params = sampler->mag_filter;
            break;
        case GL_TEXTURE_MIN_LOD:
            *params = sampler->min_lod;
            break;
        case GL_TEXTURE_MAX_LOD:
            *params = sampler->max_lod;
            break;
        case GL_TEXTURE_WRAP_S:
            *params = sampler->wrap_s;
            break;
        case GL_TEXTURE_WRAP_T:
            *params = sampler->wrap_t;
            break;
        case GL_TEXTURE_WRAP_R:
            *params = sampler->wrap_r;
            break;
        case GL_TEXTURE_COMPARE_MODE:
            *params = sampler->compare;
            break;
        case GL_TEXTURE_COMPARE_FUNC:
            *params = sampler->func;
            break;
        case GL_TEXTURE_BORDER_COLOR:
            memcpy(params, sampler->border_color, 4*sizeof(GLfloat));
            break;
        default:
            return 0;
    }
    noerrorShim();
    return 1;
}

void gl4es_glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param)
{
    glsampler_t *s = find_sampler(sampler);
    if(!s) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if(pname==GL_TEXTURE_BORDER_COLOR)
        errorShim(GL_INVALID_ENUM);
    else if(!samplerParameterfv(s, pname, &param))
        errorShim(GL_INVALID_ENUM);
    LOAD_GLES(glSamplerParameterf);
    gles_glSamplerParameterf(s->glname, pname, param);
}
void gl4es_glSamplerParameteri(GLuint sampler, GLenum pname, GLint param)
{
    glsampler_t *s = find_sampler(sampler);
    if(!s) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    GLfloat fparam = param;
    if(pname==GL_TEXTURE_BORDER_COLOR)
        errorShim(GL_INVALID_ENUM);
    else if(!samplerParameterfv(s, pname, &fparam))
        errorShim(GL_INVALID_ENUM);
    LOAD_GLES(glSamplerParameteri);
    gles_glSamplerParameteri(s->glname, pname, param);
}
void gl4es_glSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params)
{
    glsampler_t *s = find_sampler(sampler);
    if(!s) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if(!samplerParameterfv(s, pname, params))
        errorShim(GL_INVALID_ENUM);
    LOAD_GLES(glSamplerParameterfv);
    gles_glSamplerParameterfv(s->glname, pname, params);
}
void gl4es_glSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params)
{
    glsampler_t *s = find_sampler(sampler);
    if(!s) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    GLfloat fparam[4];
    fparam[0] = *params;
    if(pname==GL_TEXTURE_BORDER_COLOR)
        for(int i=0; i<4; ++i)
            fparam[i] = (params[i]>>16)*1.0f/32767.f;
    if(!samplerParameterfv(s, pname, fparam))
        errorShim(GL_INVALID_ENUM);
    if (pname == GL_TEXTURE_BORDER_COLOR) {
        LOAD_GLES(glSamplerParameterIiv);
        gles_glSamplerParameterIiv(s->glname, pname, params);
    } else {
        LOAD_GLES(glSamplerParameteriv);
        gles_glSamplerParameteriv(s->glname, pname, params);
    }
}
void gl4es_glSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params)
{
    glsampler_t *s = find_sampler(sampler);
    if(!s) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    GLfloat fparam[4];
    fparam[0] = *params;
    if(pname==GL_TEXTURE_BORDER_COLOR)
        for(int i=1; i<4; ++i)
            fparam[i] = params[i];
    if(!samplerParameterfv(s, pname, fparam))
        errorShim(GL_INVALID_ENUM);
    LOAD_GLES(glSamplerParameterIiv);
    gles_glSamplerParameterIiv(s->glname, pname, params);
}
void gl4es_glSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params)
{
    glsampler_t *s = find_sampler(sampler);
    if(!s) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    GLfloat fparam[4];
    fparam[0] = *params;
    if(pname==GL_TEXTURE_BORDER_COLOR)
        for(int i=1; i<4; ++i)
            fparam[i] = params[i];
    if(!samplerParameterfv(s, pname, fparam))
        errorShim(GL_INVALID_ENUM);
    LOAD_GLES(glSamplerParameterIuiv);
    gles_glSamplerParameterIuiv(s->glname, pname, params);
}

void gl4es_glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params)
{
    glsampler_t *s = find_sampler(sampler);
    if(!s) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if(!getSamplerParameterfv(s, pname, params))
        errorShim(GL_INVALID_ENUM);
}

void gl4es_glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLfloat * params)
{
    glsampler_t *s = find_sampler(sampler);
    if(!s) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    GLfloat fparams[4];
    if(!getSamplerParameterfv(s, pname, fparams))
        errorShim(GL_INVALID_ENUM);
    else {
        if(pname==GL_TEXTURE_BORDER_COLOR)
            for(int i=0; i<4; ++i)
                params[i]=((int)fparams[i]*32767)<<16;
        else
            params[0] = fparams[0];
    }
}

void gl4es_glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * params)
{
    glsampler_t *s = find_sampler(sampler);
    if(!s) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    GLfloat fparams[4];
    if(!getSamplerParameterfv(s, pname, fparams))
        errorShim(GL_INVALID_ENUM);
    else {
        if(pname==GL_TEXTURE_BORDER_COLOR)
            for(int i=0; i<4; ++i)
                params[i]=fparams[i];
        else
            params[0] = fparams[0];
    }
}

void gl4es_glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * params)
{
    glsampler_t *s = find_sampler(sampler);
    if(!s) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    GLfloat fparams[4];
    if(!getSamplerParameterfv(s, pname, fparams))
        errorShim(GL_INVALID_ENUM);
    else {
        if(pname==GL_TEXTURE_BORDER_COLOR)
            for(int i=0; i<4; ++i)
                params[i]=fparams[i];
        else
            params[0] = fparams[0];
    }
}

AliasExport(void, glGenSamplers, ,(GLsizei n, GLuint *ids));
AliasExport(void, glBindSampler, ,(GLuint unit, GLuint sampler));
AliasExport(void, glDeleteSamplers, ,(GLsizei n, const GLuint* samplers));
AliasExport(GLboolean, glIsSampler, ,(GLuint id));
AliasExport(void, glSamplerParameterf, ,(GLuint sampler, GLenum pname, GLfloat param));
AliasExport(void, glSamplerParameteri, ,(GLuint sampler, GLenum pname, GLint param));
AliasExport(void, glSamplerParameterfv, ,(GLuint sampler, GLenum pname, GLfloat *params));
AliasExport(void, glSamplerParameteriv, ,(GLuint sampler, GLenum pname, GLint *params));
AliasExport(void, glSamplerParameterIiv, ,(GLuint sampler, GLenum pname, GLint *params));
AliasExport(void, glSamplerParameterIuiv, ,(GLuint sampler, GLenum pname, GLuint *params));
AliasExport(void, glGetSamplerParameterfv, ,(GLuint sampler, GLenum pname, GLfloat *params));
AliasExport(void, glGetSamplerParameteriv, ,(GLuint sampler, GLenum pname, GLfloat *params));
AliasExport(void, glGetSamplerParameterIiv, ,(GLuint sampler, GLenum pname, GLint *params));
AliasExport(void, glGetSamplerParameterIuiv, ,(GLuint sampler, GLenum pname, GLuint *params));