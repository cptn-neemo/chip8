#ifndef __key_converter_h
#define __key_converter_h

unsigned char convertKeyToIndex(SDL_Keycode key) {
    switch(key) {
        case SDLK_1:
            return 1;
        case SDLK_2:
            return 2;
        case SDLK_3:
            return 3;
        case SDLK_4:
            return 12;
        case SDLK_q:
            return 4;
        case SDLK_w:
            return 5;
        case SDLK_e:
            return 6;
        case SDLK_r:
            return 13;
        case SDLK_a:
            return 7;
        case SDLK_s:
            return 8;
        case SDLK_d:
            return 9;
        case SDLK_f:
            return 14;
        case SDLK_z:
            return 10;
        case SDLK_x:
            return 0;
        case SDLK_c:
            return 11;
        case SDLK_v:
            return 15;
        default:
            return 16;
    }
}

#endif
