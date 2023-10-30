#include "hw5.h"

int main(int argc, char *argv[])
{
    // //If the argument has less than 7 command line arguments, return missing
    //   //If the argument has less than 7 command line arguments, return 1
    // if (argc < 7) {
    //     return MISSING_ARGUMENT;
    // }
    // //If there are duplicate arguments in argv, if there is more than one -s, -r, -l, or -w anywhere in argv, return 8
    // int sCount = 0;
    // int rCount = 0;
    // int lCount = 0;
    // int wCount = 0;
    // for (int i = 1; i < argc - 2; i++) {
    //     if (strcmp(argv[i], "-s") == 0) {
    //         sCount++;
    //     }
    //     if (strcmp(argv[i], "-r") == 0) {
    //         rCount++;
    //     }
    //     if (strcmp(argv[i], "-l") == 0) {
    //         lCount++;
    //     }
    //     if (strcmp(argv[i], "-w") == 0) {
    //         wCount++;
    //     }
    // }
    // if (sCount > 1 || rCount > 1 || lCount > 1 || wCount > 1) {
    //     return DUPLICATE_ARGUMENT;
    // }

    // //If we are unable to open the input file, return 2
    // FILE *inputFile = fopen(argv[argc-2], "r");
    // if (inputFile == NULL) {
    //     return INPUT_FILE_MISSING;
    // }
    // //If we are unable to open the output file, return 3
    // FILE *outputFile = fopen(argv[argc-1], "w");
    // if (outputFile == NULL) {
    //     return OUTPUT_FILE_UNWRITABLE;
    // }
    // //If -s argument is missing, or the argument to -s is missing return 4
    // bool sFlag = false;
    // char *sArg = NULL;
    // bool wsFlag = false;
    // for (int i = 1; i < argc - 2; i++) {
    //     if (strcmp(argv[i], "-s") == 0) {//If we find the -s flag
    //         sFlag = true;
    //         //Check if the first character in argv[i+1] is a dash
    //         if (argv[i+1][0] == '-') {
    //             return S_ARGUMENT_MISSING;
    //         }
    //         //Check if the argument to the -s flag contains either a '*' at the beginning or end but not both, if it does, set the wsFlag to true
    //         if ((argv[i+1][0] == '*' && argv[i+1][strlen(argv[i+1])-1] != '*') ||
    //             (argv[i+1][0] != '*' && argv[i+1][strlen(argv[i+1])-1] == '*')) {
    //             wsFlag = true;
    //         }

    //         sArg = argv[i+1];
    //         break;
    //     }
    // }
    // if (!sFlag) {
    //     return S_ARGUMENT_MISSING;
    // }
    // //If -r argument is missing, or the argument to -r is missing return 5
    // bool rFlag = false;
    // char *rArg = NULL;
    // for (int i = 1; i < argc - 2; i++) {
    //     if (strcmp(argv[i], "-r") == 0) {//If we find the -r flag
    //         rFlag = true;
    //         //Check if the first character in argv[i+1] is a dash
    //         if (argv[i+1][0] == '-') {
    //             return R_ARGUMENT_MISSING;
    //         }
    //         rArg = argv[i+1];
    //         break;
    //     }
    // }
    // if (!rFlag) {
    //     return R_ARGUMENT_MISSING;
    // }
    // //Check if the -l argument is invalid
    // //Separate the argument of the -l flag into two parts and check if they are missing or cannot be parsed
    // char *lArg1 = NULL;
    // char *lArg2 = NULL;
    // //Find the -l flag
    // for (int i = 1; i < argc - 2; i++) {
    //     if (strcmp(argv[i], "-l") == 0) {//If we find the -l flag
    //         //Check if the first character in argv[i+1] is a dash
    //         if (argv[i+1][0] == '-') {
    //             return L_ARGUMENT_INVALID;
    //         }
    //         //Check if the argument to the -l flag does not contain a comma
    //         if (strchr(argv[i+1], ',') == NULL) {
    //             return L_ARGUMENT_INVALID;
    //         }
    //         //Use strtok to separate the argument into two parts using the comma as a delimiter and then parse the two parts with strtol
    //         char *token = strtok(argv[i+1], ",");
    //         //Check if the delimiter is missing
    //         if (token == NULL) {
    //             return L_ARGUMENT_INVALID;
    //         }
    //         char *endptr;
    //         long int lArg1Long = strtol(token, &endptr, 10);
    //         if (endptr == 0) {
    //             return L_ARGUMENT_INVALID;
    //         }
    //         //Parse the second part of the argument using strtol and check if it is missing or cannot be parsed
    //         token = strtok(NULL, ",");
    //         if (token == NULL) {
    //             return L_ARGUMENT_INVALID;
    //         }
    //         long int lArg2Long = strtol(token, &endptr, 10);
    //         //If strtol fails to parse the second part of the argument
    //         if (endptr == 0) {
    //             return L_ARGUMENT_INVALID;
    //         }
    //         //If the first l argument is greater than the second l argument, return 6
    //         if (lArg1Long > lArg2Long) {
    //             return L_ARGUMENT_INVALID;
    //         }
    //         if(lArg1Long<0||lArg2Long<0){
    //             return L_ARGUMENT_INVALID;
    //         }
    //     }
    // }

    // //Check if there is a -w flag, if there is, but the argument to the -s flag doesn't have a * at the beginning or end, return 7
    // bool wFlag = false;
    // for (int i = 1; i < argc - 2; i++) {
    //     if (strcmp(argv[i], "-w") == 0) {//If we find the -w flag
    //         wFlag = true;
    //         break;
    //     }
    // }
    // if (!wsFlag&& wFlag) {
    //     return WILDCARD_INVALID;
    // }

    if (argc < 7)
    {
        return MISSING_ARGUMENT;
    }
    // If there are duplicate arguments in argv, if there is more than one -s, -r, -l, or -w anywhere in argv, return 8
    int sCount = 0;
    int rCount = 0;
    int lCount = 0;
    int wCount = 0;
    // for (int i = 1; i < argc - 2; i++) {
    //     if (strcmp(argv[i], "-s") == 0) {
    //         sCount++;
    //     }
    //     if (strcmp(argv[i], "-r") == 0) {
    //         rCount++;
    //     }
    //     if (strcmp(argv[i], "-l") == 0) {
    //         lCount++;
    //     }
    //     if (strcmp(argv[i], "-w") == 0) {
    //         wCount++;
    //     }
    // }

    char *searchArg = NULL;
    char *replaceArg = NULL;
    long int lArg1Long = 0;
    long int lArg2Long = 0;
    int wFlag = 0;
    int sFlag = 0;
    int rFlag = 0;
    int wsFlag = 0;
    // int lFlag = 0;
    int opt;
    extern char *optarg;
    extern int optind;
    while ((opt = getopt(argc, argv, "s:r:l:w")) != -1)
    {
        switch (opt)
        {
        case 's':
            sCount++;
            sFlag = 1;
            searchArg = optarg;
            // Check if the argument to the -s flag has a '*' at the beginning or end but not both, if it does, set the wsFlag to true
            if ((searchArg[0] == '*' && searchArg[strlen(searchArg) - 1] != '*') ||
                (searchArg[0] != '*' && searchArg[strlen(searchArg) - 1] == '*'))
            {
                wsFlag = 1;
            }
            break;
        case 'r':
            rCount++;
            rFlag = 1;
            replaceArg = optarg;
            break;
        case 'l':
            // Use strtok to separate the argument into two parts using the comma as a delimiter and then parse the two parts with strtol
            lCount++;
            // Check and parse the argument using optarg
                // if (optarg[0] == '-') {
                //     return L_ARGUMENT_INVALID;
                // }
                // if (strchr(optarg, ',') == NULL) {
                //     return L_ARGUMENT_INVALID;
                // }

                // char *token = strtok(optarg, ",");
                // if (token == NULL) {
                //     return L_ARGUMENT_INVALID;
                // }

                // char *endptr;
                // lArg1Long = strtol(token, &endptr, 10);
                // if (endptr == 0) {
                //     return L_ARGUMENT_INVALID;
                // }

                // token = strtok(NULL, ",");
                // if (token == NULL) {
                //     return L_ARGUMENT_INVALID;
                // }

                // lArg2Long = strtol(token, &endptr, 10);
                // if (endptr == 0) {
                //     return L_ARGUMENT_INVALID;
                // }

                // if (lArg1Long > lArg2Long || lArg1Long < 0 || lArg2Long < 0) {
                //     return L_ARGUMENT_INVALID;
                // }
            break;
        case 'w':
            wCount++;
            wFlag = 1;
        default:
            break;
        }
    }
    if (sCount > 1 || rCount > 1 || lCount > 1 || wCount > 1)
    {
        return DUPLICATE_ARGUMENT;
    }
    // If we are unable to open the input file, return 2
    FILE *inputFile = fopen(argv[argc - 2], "r");
    if (inputFile == NULL)
    {
        return INPUT_FILE_MISSING;
    }
    // If we are unable to open the output file, return 3
    FILE *outputFile = fopen(argv[argc - 1], "w");
    if (outputFile == NULL)
    {
        return OUTPUT_FILE_UNWRITABLE;
    }

    // If the -s argument is missing, or the argument to -s is missing return 4
    if (sFlag == 0)
    {
        return S_ARGUMENT_MISSING;
    }
    // Check if the argument to the -s has a '-' at the beginning
    if (searchArg[0] == '-')
    {
        return S_ARGUMENT_MISSING;
    }
    // If the -r argument is missing, or the argument to -r is missing return 5
    if (rFlag == 0)
    {
        return R_ARGUMENT_MISSING;
    }
    // Check if the argument to the -r has a '-' at the beginning
    if (replaceArg[0] == '-')
    {
        return R_ARGUMENT_MISSING;
    }
    // if (lFlag == 1)
    // {
    //     return L_ARGUMENT_INVALID;
    // }
    for (int i = 1; i < argc - 2; i++) {
        if (strcmp(argv[i], "-l") == 0) {//If we find the -l flag
            //Check if the first character in argv[i+1] is a dash
            if (argv[i+1][0] == '-') {
                return L_ARGUMENT_INVALID;
            }
            //Check if the argument to the -l flag does not contain a comma
            if (strchr(argv[i+1], ',') == NULL) {
                return L_ARGUMENT_INVALID;
            }
            //Use strtok to separate the argument into two parts using the comma as a delimiter and then parse the two parts with strtol
            char *token = strtok(argv[i+1], ",");
            //Check if the delimiter is missing
            if (token == NULL) {
                return L_ARGUMENT_INVALID;
            }
            char *endptr;
            lArg1Long = strtol(token, &endptr, 10);
            if (endptr == 0) {
                return L_ARGUMENT_INVALID;
            }
            //Parse the second part of the argument using strtol and check if it is missing or cannot be parsed
            token = strtok(NULL, ",");
            if (token == NULL) {
                return L_ARGUMENT_INVALID;
            }
            lArg2Long = strtol(token, &endptr, 10);
            //If strtol fails to parse the second part of the argument
            if (endptr == 0) {
                return L_ARGUMENT_INVALID;
            }
            //If the first l argument is greater than the second l argument, return 6
            if (lArg1Long > lArg2Long) {
                return L_ARGUMENT_INVALID;
            }
            if(lArg1Long<0||lArg2Long<0){
                return L_ARGUMENT_INVALID;
            }
        }
    }
    if (wsFlag == 0 && wFlag == 1)
    {
        return WILDCARD_INVALID;
    }
}
