/*
 * @Author: your name
 * @Date: 2020-07-26 19:18:24
 * @LastEditTime: 2020-07-27 10:29:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /voice-match/src/parser/wav.h
 */ 

#ifndef _WAV_H_
#define _WAV_H_
#include <stdint.h>

typedef struct _wav_riff {
    char chunk_id[4];
    uint32_t chunk_size;
    char format[4];
} wav_riff_t;

typedef struct _wav_format {
    char chunk_id[4];
    uint32_t sub_chunk1_size;
    uint16_t audio_format;
    uint16_t number_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
} wav_format_t;

typedef struct _wav_data {
    char chunk_id[4];
    uint32_t sub_chunk2_size;
} wav_data_t;

typedef struct wav {
    wav_riff_t riff;
    wav_format_t fmt;
    wav_data_t data;
} wav_t;

#endif