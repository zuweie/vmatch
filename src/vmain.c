/*
 * @Author: your name
 * @Date: 2020-07-26 17:21:04
 * @LastEditTime: 2020-08-12 10:30:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /voice-match/main.c
 */ 
#include <stdio.h>
#include "parser/parse_wav.h"
#include "parser/wav.h"

int show_wav_info (wav_t* w);

int main (int argc, char* argv[]) 
{
    char* wav_1 = argv[1];
    wav_t wav;
    int result =  parse_wav(wav_1, &wav);
    if (result == 0) {
        show_wav_info(&wav);
    }
    return result;
}

int show_wav_info(wav_t* w) 
{
    wav_riff_t riff  = w->riff;
    wav_format_t fmt = w->fmt;
    wav_data_t data  = w->data;

    printf("ChunkID %c%c%c%c\n", riff.chunk_id[0], riff.chunk_id[1],riff.chunk_id[2], riff.chunk_id[3]);
    printf("ChunkSize %d\n", riff.chunk_size);
    printf("Format %c%c%c%c\n", riff.format[0], riff.format[1], riff.format[2], riff.format[3]);
    printf("\n");
    printf("Subchunk1ID %c%c%c%c\n", fmt.chunk_id[0], fmt.chunk_id[1], fmt.chunk_id[2], fmt.chunk_id[3]);
    printf("Subchunk1size %d\n", fmt.sub_chunk1_size);
    printf("AudioFomat %d\n", fmt.audio_format);
    printf("NumberChannels %d\n", fmt.number_channels);
    printf("SampleRate %d\n", fmt.sample_rate);
    printf("ByteRate %d\n", fmt.byte_rate);
    printf("BlockAlign %d\n", fmt.block_align);
    printf("BitsPerSample %d\n", fmt.bits_per_sample);
    printf("\n");
    printf("BlockID %c%c%c%c\n",data.chunk_id[0], data.chunk_id[1], data.chunk_id[2], data.chunk_id[3]);
    printf("BlockSize %d \n", data.sub_chunk2_size);
    printf("\n");
    printf("duration: %d \n", data.sub_chunk2_size / fmt.byte_rate);
    printf("sizeof wav_t %d\n", sizeof(wav_t));
}