#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "logs.h"
#include "gl4es.h"

static cJSON *config_json = nullptr;

void config_refresh() {
    FILE *file = fopen(CONFIG_FILE_PATH, "r");
    if (file == nullptr) {
        SHUT_LOGE("Unable to open config file %s", CONFIG_FILE_PATH);
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *file_content = (char *)malloc(file_size + 1);
    if (file_content == nullptr) {
        SHUT_LOGE("Unable to allocate memory for file content");
        fclose(file);
        return;
    }

    fread(file_content, 1, file_size, file);
    fclose(file);
    file_content[file_size] = '\0';

    config_json = cJSON_Parse(file_content);
    if (config_json == nullptr) {
        SHUT_LOGE("Error parsing config JSON: %s\n", cJSON_GetErrorPtr());
    }

    free(file_content);
}

int config_get_int(char* name) {
    if (config_json == nullptr) {
        return -1;
    }

    cJSON *item = cJSON_GetObjectItem(config_json, name);
    if (item == nullptr || !cJSON_IsNumber(item)) {
        SHUT_LOGD("Config item '%s' not found or not an integer.\n", name);
        return -1;
    }

    return item->valueint;
}

char* config_get_string(char* name) {
    if (config_json == nullptr) {
        return nullptr;
    }

    cJSON *item = cJSON_GetObjectItem(config_json, name);
    if (item == nullptr || !cJSON_IsString(item)) {
        SHUT_LOGD("Config item '%s' not found or not a string.\n", name);
        return nullptr; 
    }

    return item->valuestring;
}

void config_cleanup() {
    if (config_json != nullptr) {
        cJSON_Delete(config_json);
        config_json = nullptr;
    }
}
