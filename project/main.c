#include "main.h"
#include "datastructures/input.h"

int main(int argc, char* argv[]) {
    int opt;
    int algo_num = 0;
    bool decode = false, encode = false, algo_picked = false;
    FunctionPointer encoders[] = {&huffman_encode};
    FunctionPointer decoders[] = {&huffman_decode};

    //Parse options
    while((opt = getopt(argc, argv, "t:cd")) != -1){
        switch(opt){
            case 't':
                algo_num = (int) strtol(optarg, NULL, 10);
                //prevent dubious algorithm picks & check if it actually is possible
                if(algo_num>0&&algo_num<=MAX_NUM&&!algo_picked){
                    algo_picked = true;
                    //start counting from 0 for array interaction!
                    algo_num--;
                } else {
                    return INCORRECT_OPTS;
                }
                break;
            case 'c':
                encode = true;
                break;
            case 'd':
                decode = true;
                break;
            default:
                return INCORRECT_OPTS;
        }
    }

    //Check options
    //encode and decode flags are not set, or both set
    if((decode&&encode)||(!encode&&!decode)){
        return INCORRECT_OPTS;
    } else if(encode) { //call the algorithm
        encoders[algo_num]();
    }


    return 0;
}

