#include <GL/gl.h>
#include "vertexattrib.h"

#include "../glx/hardext.h"
#include "buffers.h"
#include "enum_info.h"
#include "gl4es.h"
#include "glstate.h"

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif

void APIENTRY_GL4ES gl4es_glVertexAttribL1d(GLuint index, GLdouble x) {
    DBG(SHUT_LOGD("glVertexAttribL1d(%d, %f)\n", index, x);)
        FLUSH_BEGINEND;

    if (index >= hardext.maxvattrib || index < 0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }

    GLfloat v[4] = { (GLfloat)x, 0.0f, 0.0f, 0.0f };
    if (memcmp(glstate->vavalue[index], v, 4 * sizeof(GLfloat)) == 0) {
        noerrorShim();
        return;
    }

    memcpy(glstate->vavalue[index], v, 4 * sizeof(GLfloat));
}

void APIENTRY_GL4ES gl4es_glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) {
    DBG(SHUT_LOGD("glVertexAttribL2d(%d, %f, %f)\n", index, x, y);)
        FLUSH_BEGINEND;

    if (index >= hardext.maxvattrib || index < 0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }

    GLfloat v[4] = { (GLfloat)x, (GLfloat)y, 0.0f, 0.0f };
    if (memcmp(glstate->vavalue[index], v, 4 * sizeof(GLfloat)) == 0) {
        noerrorShim();
        return;
    }

    memcpy(glstate->vavalue[index], v, 4 * sizeof(GLfloat));
}

void APIENTRY_GL4ES gl4es_glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    DBG(SHUT_LOGD("glVertexAttribL3d(%d, %f, %f, %f)\n", index, x, y, z);)
        FLUSH_BEGINEND;

    if (index >= hardext.maxvattrib || index < 0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }

    GLfloat v[4] = { (GLfloat)x, (GLfloat)y, (GLfloat)z, 0.0f };
    if (memcmp(glstate->vavalue[index], v, 4 * sizeof(GLfloat)) == 0) {
        noerrorShim();
        return;
    }

    memcpy(glstate->vavalue[index], v, 4 * sizeof(GLfloat));
}

void APIENTRY_GL4ES gl4es_glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    DBG(SHUT_LOGD("glVertexAttribL4d(%d, %f, %f, %f, %f)\n", index, x, y, z, w);)
        FLUSH_BEGINEND;

    if (index >= hardext.maxvattrib || index < 0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }

    GLfloat v[4] = { (GLfloat)x, (GLfloat)y, (GLfloat)z, (GLfloat)w };
    if (memcmp(glstate->vavalue[index], v, 4 * sizeof(GLfloat)) == 0) {
        noerrorShim();
        return;
    }

    memcpy(glstate->vavalue[index], v, 4 * sizeof(GLfloat));
}

void APIENTRY_GL4ES gl4es_glVertexAttribL1dv(GLuint index, const GLdouble* v) {
    DBG(SHUT_LOGD("glVertexAttribL1dv(%d, %p)\n", index, v);)
        FLUSH_BEGINEND;

    if (index >= hardext.maxvattrib || index < 0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }

    GLfloat value[4] = { (GLfloat)v[0], 0.0f, 0.0f, 0.0f };
    if (memcmp(glstate->vavalue[index], value, 4 * sizeof(GLfloat)) == 0) {
        noerrorShim();
        return;
    }

    memcpy(glstate->vavalue[index], value, 4 * sizeof(GLfloat));
}

void APIENTRY_GL4ES gl4es_glVertexAttribL2dv(GLuint index, const GLdouble* v) {
    DBG(SHUT_LOGD("glVertexAttribL2dv(%d, %p)\n", index, v);)
        FLUSH_BEGINEND;

    if (index >= hardext.maxvattrib || index < 0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }

    GLfloat value[4] = { (GLfloat)v[0], (GLfloat)v[1], 0.0f, 0.0f };
    if (memcmp(glstate->vavalue[index], value, 4 * sizeof(GLfloat)) == 0) {
        noerrorShim();
        return;
    }

    memcpy(glstate->vavalue[index], value, 4 * sizeof(GLfloat));
}

void APIENTRY_GL4ES gl4es_glVertexAttribL3dv(GLuint index, const GLdouble* v) {
    DBG(SHUT_LOGD("glVertexAttribL3dv(%d, %p)\n", index, v);)
        FLUSH_BEGINEND;

    if (index >= hardext.maxvattrib || index < 0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }

    GLfloat value[4] = { (GLfloat)v[0], (GLfloat)v[1], (GLfloat)v[2], 0.0f };
    if (memcmp(glstate->vavalue[index], value, 4 * sizeof(GLfloat)) == 0) {
        noerrorShim();
        return;
    }

    memcpy(glstate->vavalue[index], value, 4 * sizeof(GLfloat));
}

void APIENTRY_GL4ES gl4es_glVertexAttribL4dv(GLuint index, const GLdouble* v) {
    DBG(SHUT_LOGD("glVertexAttribL4dv(%d, %p)\n", index, v);)
        FLUSH_BEGINEND;

    if (index >= hardext.maxvattrib || index < 0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }

    GLfloat value[4] = { (GLfloat)v[0], (GLfloat)v[1], (GLfloat)v[2], (GLfloat)v[3] };
    if (memcmp(glstate->vavalue[index], value, 4 * sizeof(GLfloat)) == 0) {
        noerrorShim();
        return;
    }

    memcpy(glstate->vavalue[index], value, 4 * sizeof(GLfloat));
}

void APIENTRY_GL4ES gl4es_glBindVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* strides) {
    glstate_t* glstate = glstate;
    glvao_t* vao = glstate->vao;

    if (!vao) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }

    for (GLsizei i = 0; i < count; ++i) {
        GLuint buffer = buffers[i];
        GLintptr offset = offsets ? offsets[i] : 0;
        GLsizeiptr stride = strides ? strides[i] : 0;
        khash_t(buff)* buffers_map = glstate->buffers;
        khint_t k = kh_get(buff, buffers_map, buffer);

        if (k == kh_end(buffers_map)) {
            errorShim(GL_INVALID_OPERATION);
            return;
        }

        glbuffer_t* glbuffer = kh_value(buffers_map, k);

        vao->vertexattrib[first + i].buffer = glbuffer;
        vao->vertexattrib[first + i].pointer = (const void*)offset;
        vao->vertexattrib[first + i].stride = stride;
        vao->vertexattrib[first + i].enabled = 1;
    }
}



void APIENTRY_GL4ES gl4es_glBindVertexBuffer(GLuint bindingIndex, GLuint buffer, GLintptr offset, GLsizeiptr stride) {
    glstate_t* glstate = glstate;

    khash_t(buff)* buffers = glstate->buffers;
    khint_t k = kh_get(buff, buffers, buffer);

    if (k == kh_end(buffers)) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }

    glbuffer_t* glbuffer = kh_value(buffers, k);

    glvao_t* vao = glstate->vao;

    if (vao) {
        vao->vertexattrib[bindingIndex].buffer = glbuffer;
        vao->vertexattrib[bindingIndex].pointer = (const void*)offset;
        vao->vertexattrib[bindingIndex].stride = stride;
        vao->vertexattrib[bindingIndex].enabled = 1;
    }
    else {
        errorShim(GL_INVALID_OPERATION);
    }
}

void APIENTRY_GL4ES gl4es_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) {
    DBG(SHUT_LOGD("glVertexAttribPointer(%d, %d, %s, %d, %d, %p), vertex %p buffer = %p\n", index, size, PrintEnum(type), normalized, stride, pointer, glstate->vao->vertex, (glstate->vao->vertex)?glstate->vao->vertex->data:0);)
    FLUSH_BEGINEND;
    // sanity test
    if(index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if(size<1 || (size>4 && size!=GL_BGRA)) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    // TODO: test Type also
    vertexattrib_t *v = &glstate->vao->vertexattrib[index];
    noerrorShim();
    if(stride==0) stride=((size==GL_BGRA)?4:size)*gl_sizeof(type);
    v->size = size;
    v->type = type;
    v->normalized = normalized;
    v->integer = 0;
    v->stride = stride;
    v->pointer = pointer;
    v->buffer = glstate->vao->vertex;
    if( v->buffer ) {
		v->real_buffer = v->buffer->real_buffer;
		v->real_pointer = pointer;
	} else {
        v->real_buffer = 0;
        v->real_pointer = 0;
    }
}
void APIENTRY_GL4ES gl4es_glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    DBG(SHUT_LOGD("glVertexAttribIPointer(%d, %d, %s, %d, %p), vertex buffer = %p\n", index, size, PrintEnum(type), stride, pointer, (glstate->vao->vertex)?glstate->vao->vertex->data:0);)
    FLUSH_BEGINEND;
    // sanity test
    if(index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if(size<1 || (size>4 && size!=GL_BGRA)) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    // TODO: test Type also
    vertexattrib_t *v = &glstate->vao->vertexattrib[index];
    noerrorShim();
    if(stride==0) stride=((size==GL_BGRA)?4:size)*gl_sizeof(type);
    v->size = size;
    v->type = type;
    v->normalized = 0;
    v->integer = 1;
    v->stride = stride;
    v->pointer = pointer;
    v->buffer = glstate->vao->vertex;
    if( v->buffer ) {
		v->real_buffer = v->buffer->real_buffer;
		v->real_pointer = pointer;
	} else {
        v->real_buffer = 0;
        v->real_pointer = 0;
    }
}
void APIENTRY_GL4ES gl4es_glEnableVertexAttribArray(GLuint index) {
    DBG(SHUT_LOGD("glEnableVertexAttrib(%d)\n", index);)
    FLUSH_BEGINEND;
    // sanity test
    if(index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vao->vertexattrib[index].enabled = 1;
}
void APIENTRY_GL4ES gl4es_glDisableVertexAttribArray(GLuint index) {
    DBG(SHUT_LOGD("glDisableVertexAttrib(%d)\n", index);)
    FLUSH_BEGINEND;
    // sanity test
    if(index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vao->vertexattrib[index].enabled = 0;
}

// TODO: move the sending of the data to the Hardware when drawing, to cache change of state
void APIENTRY_GL4ES gl4es_glVertexAttrib4f(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    DBG(SHUT_LOGD("glVertexAttrib4f(%d, %f, %f, %f, %f)\n", index, v0, v1, v2, v3);)
    FLUSH_BEGINEND;
    static GLfloat f[4];
    f[0] = v0; f[1] = v1; f[2] = v2; f[3] = v3;
    gl4es_glVertexAttrib4fv(index, f);
}
void APIENTRY_GL4ES gl4es_glVertexAttrib4fv(GLuint index, const GLfloat *v) {
    DBG(SHUT_LOGD("glVertexAttrib4fv(%d, %p)\n", index, v);)
    FLUSH_BEGINEND;
    // sanity test
    if(index<0 || index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    // test if changed
    if(memcmp(glstate->vavalue[index], v, 4*sizeof(GLfloat))==0) {
        noerrorShim();
        return;
    }
    memcpy(glstate->vavalue[index], v, 4*sizeof(GLfloat));
}

#define GetVertexAttrib(suffix, Type, factor) \
void APIENTRY_GL4ES gl4es_glGetVertexAttrib##suffix##v(GLuint index, GLenum pname, Type *params) { \
    FLUSH_BEGINEND; \
    if(index<0 || index>=hardext.maxvattrib) { \
        errorShim(GL_INVALID_VALUE); \
        return; \
    } \
    noerrorShim(); \
    switch(pname) { \
        case GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING: \
            *params=(glstate->vao->vertexattrib[index].buffer)?glstate->vao->vertexattrib[index].buffer->buffer:0; \
            return; \
        case GL_VERTEX_ATTRIB_ARRAY_ENABLED: \
            *params=(glstate->vao->vertexattrib[index].enabled)?1:0; \
            return; \
        case GL_VERTEX_ATTRIB_ARRAY_SIZE: \
            *params=glstate->vao->vertexattrib[index].size; \
            return; \
        case GL_VERTEX_ATTRIB_ARRAY_STRIDE: \
            *params=glstate->vao->vertexattrib[index].stride; \
            return; \
        case GL_VERTEX_ATTRIB_ARRAY_TYPE: \
            *params=glstate->vao->vertexattrib[index].type; \
            return; \
        case GL_VERTEX_ATTRIB_ARRAY_NORMALIZED: \
            *params=glstate->vao->vertexattrib[index].normalized; \
            return; \
        case GL_CURRENT_VERTEX_ATTRIB: \
            if(glstate->vao->vertexattrib[index].normalized) \
                for (int i=0; i<4; i++) \
                    *params=glstate->vavalue[index][i]*factor; \
            else    \
                for (int i=0; i<4; i++) \
                    *params=glstate->vavalue[index][i]; \
            return; \
        case GL_VERTEX_ATTRIB_ARRAY_DIVISOR: \
            *params=glstate->vao->vertexattrib[index].divisor; \
            return; \
    } \
    errorShim(GL_INVALID_ENUM); \
}

GetVertexAttrib(d, GLdouble, 1.0);
GetVertexAttrib(f, GLfloat, 1.0f);
GetVertexAttrib(i, GLint, 2147483647.0f);
#undef GetVertexAttrib

void APIENTRY_GL4ES gl4es_glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid **pointer) {
    FLUSH_BEGINEND;
    // sanity test
    if(index<0 || index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if (pname!=GL_VERTEX_ATTRIB_ARRAY_POINTER) {
        errorShim(GL_INVALID_ENUM);
        return;
    }
    *pointer = (GLvoid*)glstate->vao->vertexattrib[index].pointer;
    noerrorShim();
}

void APIENTRY_GL4ES gl4es_glVertexAttribDivisor(GLuint index, GLuint divisor) {
    FLUSH_BEGINEND;
    // sanity test
    if(index<0 || index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vao->vertexattrib[index].divisor = divisor;
}


void APIENTRY_GL4ES gl4es_glVertexAttribI1i(GLuint index, GLint x) {
    DBG(SHUT_LOGD("glVertexAttribI1i(%d, %d)\n", index, x);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)x;
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI2i(GLuint index, GLint x, GLint y) {
    DBG(SHUT_LOGD("glVertexAttribI2i(%d, %d, %d)\n", index, x, y);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)x;
    glstate->vavalue[index][1] = (GLfloat)y;
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) {
    DBG(SHUT_LOGD("glVertexAttribI3i(%d, %d, %d, %d)\n", index, x, y, z);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)x;
    glstate->vavalue[index][1] = (GLfloat)y;
    glstate->vavalue[index][2] = (GLfloat)z;
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) {
    DBG(SHUT_LOGD("glVertexAttribI4i(%d, %d, %d, %d, %d)\n", index, x, y, z, w);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)x;
    glstate->vavalue[index][1] = (GLfloat)y;
    glstate->vavalue[index][2] = (GLfloat)z;
    glstate->vavalue[index][3] = (GLfloat)w;
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI1ui(GLuint index, GLuint x) {
    DBG(SHUT_LOGD("glVertexAttribI1ui(%d, %u)\n", index, x);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)x;
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) {
    DBG(SHUT_LOGD("glVertexAttribI2ui(%d, %u, %u)\n", index, x, y);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)x;
    glstate->vavalue[index][1] = (GLfloat)y;
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) {
    DBG(SHUT_LOGD("glVertexAttribI3ui(%d, %u, %u, %u)\n", index, x, y, z);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)x;
    glstate->vavalue[index][1] = (GLfloat)y;
    glstate->vavalue[index][2] = (GLfloat)z;
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    DBG(SHUT_LOGD("glVertexAttribI4ui(%d, %u, %u, %u, %u)\n", index, x, y, z, w);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)x;
    glstate->vavalue[index][1] = (GLfloat)y;
    glstate->vavalue[index][2] = (GLfloat)z;
    glstate->vavalue[index][3] = (GLfloat)w;
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI1iv(GLuint index, const GLint* v) {
    DBG(SHUT_LOGD("glVertexAttribI1iv(%d, %p)\n", index, v);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)v[0];
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI2iv(GLuint index, const GLint* v) {
    DBG(SHUT_LOGD("glVertexAttribI2iv(%d, %p)\n", index, v);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)v[0];
    glstate->vavalue[index][1] = (GLfloat)v[1];
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI3iv(GLuint index, const GLint* v) {
    DBG(SHUT_LOGD("glVertexAttribI3iv(%d, %p)\n", index, v);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)v[0];
    glstate->vavalue[index][1] = (GLfloat)v[1];
    glstate->vavalue[index][2] = (GLfloat)v[2];
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI4iv(GLuint index, const GLint* v) {
    DBG(SHUT_LOGD("glVertexAttribI4iv(%d, %p)\n", index, v);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)v[0];
    glstate->vavalue[index][1] = (GLfloat)v[1];
    glstate->vavalue[index][2] = (GLfloat)v[2];
    glstate->vavalue[index][3] = (GLfloat)v[3];
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI1uiv(GLuint index, const GLuint* v) {
    DBG(SHUT_LOGD("glVertexAttribI1uiv(%d, %p)\n", index, v);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)v[0];
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI2uiv(GLuint index, const GLuint* v) {
    DBG(SHUT_LOGD("glVertexAttribI2uiv(%d, %p)\n", index, v);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)v[0];
    glstate->vavalue[index][1] = (GLfloat)v[1];
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI3uiv(GLuint index, const GLuint* v) {
    DBG(SHUT_LOGD("glVertexAttribI3uiv(%d, %p)\n", index, v);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)v[0];
    glstate->vavalue[index][1] = (GLfloat)v[1];
    glstate->vavalue[index][2] = (GLfloat)v[2];
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribI4uiv(GLuint index, const GLuint* v) {
    DBG(SHUT_LOGD("glVertexAttribI4uiv(%d, %p)\n", index, v);)
        FLUSH_BEGINEND;
    if (index < 0 || index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vavalue[index][0] = (GLfloat)v[0];
    glstate->vavalue[index][1] = (GLfloat)v[1];
    glstate->vavalue[index][2] = (GLfloat)v[2];
    glstate->vavalue[index][3] = (GLfloat)v[3];
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    DBG(SHUT_LOGD("glVertexAttribP1ui(%d, %s, %d, %u)\n", index, PrintEnum(type), normalized, value);)
        FLUSH_BEGINEND;
    if (index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if (glstate->vao) {
        glstate->vao->vertexattrib[index].type = type;
        glstate->vao->vertexattrib[index].enabled = 1;
        glstate->vao->vertexattrib[index].normalized = normalized;
        glstate->vao->vertexattrib[index].pointer = (const GLvoid*)(uintptr_t)value;
    }
    else {
        errorShim(GL_INVALID_OPERATION);
    }
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    DBG(SHUT_LOGD("glVertexAttribP2ui(%d, %s, %d, %u)\n", index, PrintEnum(type), normalized, value);)
        FLUSH_BEGINEND;
    if (index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if (glstate->vao) {
        glstate->vao->vertexattrib[index].type = type;
        glstate->vao->vertexattrib[index].enabled = 1;
        glstate->vao->vertexattrib[index].normalized = normalized;
        glstate->vao->vertexattrib[index].pointer = (const GLvoid*)(uintptr_t)value;
    }
    else {
        errorShim(GL_INVALID_OPERATION); 
    }
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    DBG(SHUT_LOGD("glVertexAttribP3ui(%d, %s, %d, %u)\n", index, PrintEnum(type), normalized, value);)
        FLUSH_BEGINEND;
    if (index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if (glstate->vao) {
        glstate->vao->vertexattrib[index].type = type;
        glstate->vao->vertexattrib[index].enabled = 1;
        glstate->vao->vertexattrib[index].normalized = normalized;
        glstate->vao->vertexattrib[index].pointer = (const GLvoid*)(uintptr_t)value;
    }
    else {
        errorShim(GL_INVALID_OPERATION);
    }
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    DBG(SHUT_LOGD("glVertexAttribP4ui(%d, %s, %d, %u)\n", index, PrintEnum(type), normalized, value);)
        FLUSH_BEGINEND;
    if (index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if (glstate->vao) {
        glstate->vao->vertexattrib[index].type = type;
        glstate->vao->vertexattrib[index].enabled = 1;
        glstate->vao->vertexattrib[index].normalized = normalized;
        glstate->vao->vertexattrib[index].pointer = (const GLvoid*)(uintptr_t)value;
    }
    else {
        errorShim(GL_INVALID_OPERATION); 
    }
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) {
    DBG(SHUT_LOGD("glVertexAttribP1uiv(%d, %s, %d, %p)\n", index, PrintEnum(type), normalized, value);)
        FLUSH_BEGINEND;
    if (index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if (glstate->vao) {
        glstate->vao->vertexattrib[index].type = type;
        glstate->vao->vertexattrib[index].enabled = 1;
        glstate->vao->vertexattrib[index].normalized = normalized;
        glstate->vao->vertexattrib[index].pointer = (const GLvoid*)value;
    }
    else {
        errorShim(GL_INVALID_OPERATION);
    }
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) {
    DBG(SHUT_LOGD("glVertexAttribP2uiv(%d, %s, %d, %p)\n", index, PrintEnum(type), normalized, value);)
        FLUSH_BEGINEND;
    if (index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if (glstate->vao) {
        glstate->vao->vertexattrib[index].type = type;
        glstate->vao->vertexattrib[index].enabled = 1;
        glstate->vao->vertexattrib[index].normalized = normalized;
        glstate->vao->vertexattrib[index].pointer = (const GLvoid*)value;
    }
    else {
        errorShim(GL_INVALID_OPERATION);
    }
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) {
    DBG(SHUT_LOGD("glVertexAttribP3uiv(%d, %s, %d, %p)\n", index, PrintEnum(type), normalized, value);)
        FLUSH_BEGINEND;
    if (index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if (glstate->vao) {
        glstate->vao->vertexattrib[index].type = type;
        glstate->vao->vertexattrib[index].enabled = 1;
        glstate->vao->vertexattrib[index].normalized = normalized;
        glstate->vao->vertexattrib[index].pointer = (const GLvoid*)value;
    }
    else {
        errorShim(GL_INVALID_OPERATION);
    }
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) {
    DBG(SHUT_LOGD("glVertexAttribP4uiv(%d, %s, %d, %p)\n", index, PrintEnum(type), normalized, value);)
        FLUSH_BEGINEND;
    if (index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if (glstate->vao) {
        glstate->vao->vertexattrib[index].type = type;
        glstate->vao->vertexattrib[index].enabled = 1;
        glstate->vao->vertexattrib[index].normalized = normalized;
        glstate->vao->vertexattrib[index].pointer = (const GLvoid*)value;
    }
    else {
        errorShim(GL_INVALID_OPERATION); 
    }
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) {
    DBG(SHUT_LOGD("glVertexAttribLPointer(%d, %d, %s, %d, %p)\n", index, size, PrintEnum(type), stride, pointer);)
        FLUSH_BEGINEND;
    if (index >= hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    vertexattrib_t* attrib = &glstate->vao->vertexattrib[index];
    attrib->size = size;
    attrib->type = type;
    attrib->stride = stride;
    attrib->pointer = pointer;
    attrib->enabled = 1;
    attrib->normalized = 0;
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble* params) {
    DBG(SHUT_LOGD("glGetVertexAttribLdv(%d, %s, %p)\n", index, PrintEnum(pname), params);)
        if (index >= hardext.maxvattrib) {
            errorShim(GL_INVALID_VALUE);
            return;
        }
    vertexattrib_t* attrib = &glstate->vao->vertexattrib[index];
    switch (pname) {
    case GL_VERTEX_ATTRIB_ARRAY_SIZE:
        *params = (GLdouble)attrib->size;
        break;
    case GL_VERTEX_ATTRIB_ARRAY_STRIDE:
        *params = (GLdouble)attrib->stride;
        break;
    case GL_VERTEX_ATTRIB_ARRAY_TYPE:
        *params = (GLdouble)attrib->type;
        break;
    case GL_VERTEX_ATTRIB_ARRAY_POINTER:
        *params = (GLdouble)(uintptr_t)attrib->pointer;
        break;
    default:
        errorShim(GL_INVALID_ENUM);
        return;
    }
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params) {
    DBG(SHUT_LOGD("glGetVertexAttribIiv(%d, %s, %p)\n", index, PrintEnum(pname), params);)
        if (index >= hardext.maxvattrib) {
            errorShim(GL_INVALID_VALUE);
            return;
        }
    vertexattrib_t* attrib = &glstate->vao->vertexattrib[index];
    switch (pname) {
    case GL_VERTEX_ATTRIB_ARRAY_SIZE:
        *params = (GLint)attrib->size;
        break;
    case GL_VERTEX_ATTRIB_ARRAY_STRIDE:
        *params = (GLint)attrib->stride;
        break;
    case GL_VERTEX_ATTRIB_ARRAY_TYPE:
        *params = (GLint)attrib->type;
        break;
    case GL_VERTEX_ATTRIB_ARRAY_POINTER:
        *params = (GLint)(uintptr_t)attrib->pointer;
        break;
    default:
        errorShim(GL_INVALID_ENUM);
        return;
    }
    noerrorShim();
}
void APIENTRY_GL4ES gl4es_glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params) {
    DBG(SHUT_LOGD("glGetVertexAttribIuiv(%d, %s, %p)\n", index, PrintEnum(pname), params);)
        if (index >= hardext.maxvattrib) {
            errorShim(GL_INVALID_VALUE);
            return;
        }
    vertexattrib_t* attrib = &glstate->vao->vertexattrib[index];
    switch (pname) {
    case GL_VERTEX_ATTRIB_ARRAY_SIZE:
        *params = (GLuint)attrib->size;
        break;
    case GL_VERTEX_ATTRIB_ARRAY_STRIDE:
        *params = (GLuint)attrib->stride;
        break;
    case GL_VERTEX_ATTRIB_ARRAY_TYPE:
        *params = (GLuint)attrib->type;
        break;
    case GL_VERTEX_ATTRIB_ARRAY_POINTER:
        *params = (GLuint)(uintptr_t)attrib->pointer;
        break;
    default:
        errorShim(GL_INVALID_ENUM);
        return;
    }
    noerrorShim();
}

/*
AliasExport(void,glVertexAttribPointer,,(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer));
AliasExport(void,glVertexAttribIPointer,,(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer));
AliasExport(void,glEnableVertexAttribArray,,(GLuint index));
AliasExport(void,glDisableVertexAttribArray,,(GLuint index));
AliasExport(void,glVertexAttrib4f,,(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3));
AliasExport(void,glVertexAttrib4fv,,(GLuint index, const GLfloat *v));
AliasExport(void,glGetVertexAttribdv,,(GLuint index, GLenum pname, GLdouble *params));
AliasExport(void,glGetVertexAttribfv,,(GLuint index, GLenum pname, GLfloat *params));
AliasExport(void,glGetVertexAttribiv,,(GLuint index, GLenum pname, GLint *params));
AliasExport(void,glGetVertexAttribPointerv,,(GLuint index, GLenum pname, GLvoid **pointer));
*/

// ============= GL_ARB_vertex_shader =================
AliasExport(GLvoid,glVertexAttrib4f,ARB,(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3));
AliasExport(GLvoid,glVertexAttrib4fv,ARB,(GLuint index, const GLfloat *v));

AliasExport(GLvoid,glVertexAttribPointer,ARB,(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer));

AliasExport(GLvoid,glEnableVertexAttribArray,ARB,(GLuint index));
AliasExport(GLvoid,glDisableVertexAttribArray,ARB,(GLuint index));

AliasExport(GLvoid,glGetVertexAttribdv,ARB,(GLuint index, GLenum pname, GLdouble *params));
AliasExport(GLvoid,glGetVertexAttribfv,ARB,(GLuint index, GLenum pname, GLfloat *params));
AliasExport(GLvoid,glGetVertexAttribiv,ARB,(GLuint index, GLenum pname, GLint *params));
AliasExport(GLvoid,glGetVertexAttribPointerv,ARB,(GLuint index, GLenum pname, GLvoid **pointer));

// ============== GL_ARB_instanced_arrays =================
AliasExport(void,glVertexAttribDivisor,,(GLuint index, GLuint divisor));
AliasExport(void,glVertexAttribDivisor,ARB,(GLuint index, GLuint divisor));