/*
 * @Author: your name
 * @Date: 2020-07-26 17:20:53
 * @LastEditTime: 2020-08-13 21:22:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /voice-match/parse_wav.c
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "wav.h"
#include "parse_wav.h"

static int parse_wav_header (FILE* fp, wav_t* wav) 
{
    fread(wav, 1, sizeof(wav_t), fp);
    return 0;
}

static int get_mfcc(void* buffer) {
    return 0;
}

/**
 * 获取 wav 文件中的波形数据
 */
static float* fatch_wav_data (FILE* f, wav_t* wav, size_t* data_len) {
    // 把音频波形数据读入内存里面。已浮点来存储
    int sample_byte_size = wav->fmt.bits_per_sample / 8;
    
    int buffer_len = (wav->data.sub_chunk2_size / sample_byte_size) * sizeof(float);

    float* buffer = (float*) malloc (buffer_len);

    if (wav->fmt.bits_per_sample == 32) {
        // 32 位的是浮点。
        fread(buffer, sample_byte_size, wav->data.sub_chunk2_size/sample_byte_size, f);
    }else {
        // 如果是 8 或者 16位的 把它做成浮点。
        int word_width = wav->fmt.bits_per_sample / 8;
        int read;
        size_t read_number = 0, i=0;

        while((read_number = fread(&read, word_width, 1, f)) != 0 && i<buffer_len) {
            buffer[i++] = (float) read;
        }
        *data_len = i;
    }
    return buffer;
}

static void pre_emphasizing(float* buffer, size_t data_len, float factor) 
{
    for(size_t i=1; i<data_len; ++i) {
        buffer[i] = buffer[i-1] * factor;
    }
}

static int frameing (float* buffer, size_t data_len, wav_t* wav, float frame_time) 
{
    
}

int parse_wav (char* wav_dir, wav_t* wav) 
{
    FILE* fp = fopen(wav_dir, "rb");
    if (fp == NULL) {
        return -1;
    }
    // 1 分析头部
    parse_wav_header(fp, wav);

    // 2 读取数据。
    size_t data_len;
    float* buffer = fatch_wav_data(fp, wav, &data_len);

    pre_emphasizing(buffer, data_len, 0.96);

    

    free(buffer);

    return 0;
}