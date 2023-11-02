#include "hw5.h"

//Helper boolean
int is_punct_or_space(char c) {
    return isspace(c) || ispunct(c);
}
//Helper function to replace the words in oldLine with the suffix of searchArg with replaceArg
char* suffixReplace(const char* oldLine, const char* searchArg, const char* replaceArg) {
    int i, j, count = 0;
    int searchArglen = strlen(searchArg);//Length of searchArg string
    int replaceArglen = strlen(replaceArg);//Length of replaceArg string
    char* newLine;//New line that helper function returns
    
    //Find the number of times the suffix is a the end of a word
    for (i = 0; oldLine[i] != '\0';) { 
        //Check if its the beginning of a word
        if (i == 0 || is_punct_or_space(oldLine[i-1])) { 
            int beginning = i; 
            //Find the end of the word
            while (oldLine[i] != '\0' && !isspace(oldLine[i]) && !ispunct(oldLine[i])) { 
                i++;
            }
            int end = i - 1; 
            //If the suffix is at the end of the word increment count
            if (end - beginning + 1 >= searchArglen && strncmp(&oldLine[end - searchArglen + 1], searchArg, searchArglen) == 0) { 
                count++;                                                                                                   
            }
            if (oldLine[i] != '\0') i++;  
        } else {
            i++;
        }
    }

    newLine = malloc(strlen(oldLine) + count * (replaceArglen - searchArglen) + 1); 

    i = 0;
    int k = 0;
    while (oldLine[i]) { 
        //Check if its the beginning of a word
        if (i == 0 || is_punct_or_space(oldLine[i-1])) { 
            int beginning = i;
            //Find the index of the end of the word
            while (oldLine[i] != '\0' && !isspace(oldLine[i]) && !ispunct(oldLine[i])) { 
                i++;
            }
            int end = i - 1; 
            //If the suffix is at the end of the word then replace the searchArg with replaceArg
            if (end - beginning + 1 >= searchArglen && strncmp(&oldLine[end - searchArglen + 1], searchArg, searchArglen) == 0) {
                for (j = 0; j < replaceArglen; j++) {
                    newLine[k] = replaceArg[j];
                    k++; 
                }
                while (oldLine[i] != '\0' && (is_punct_or_space(oldLine[i]))) {
                    newLine[k] = oldLine[i]; 
                    k++;
                    i++;
                }
                //Else you copy from the oldLine
            } else {
                while (beginning <= end) { 
                    newLine[k] = oldLine[beginning];
                    k++;
                    beginning++;
                }
                while (oldLine[i] != '\0' && (is_punct_or_space(oldLine[i]))) {
                    newLine[k] = oldLine[i]; 
                    k++;
                    i++;
                }
            }
            //If not the beginning of a word then copy from the oldLine
        } else { 
            newLine[k] = oldLine[i];
            k++;
            i++;
        }
    }
    //Add the null terminator 
    newLine[k] = '\0';
    return newLine;
}
char *replace(char *oldLine, char *searchAr, char *replaceAr)
{
    // get the lengths of the line, search argument and new argument
    int searchArlen = strlen(searchAr);
    int replaceArlen = strlen(replaceAr);
    int oldLine_len = strlen(oldLine);

    char *newLine;

    // If the length of the search argument is the same as the new replacement arg,newLine is the same length as oldLine
    if (searchArlen == replaceArlen)
    {
        newLine = malloc((oldLine_len + 1) * sizeof(char));
    }
    // Else we have to find the new length of newLine
    else
    {
        int wordCount = 0;
        int i = 0;
        while (i < oldLine_len)
        {
            // Checks if the search argument is the first occurence of the oldLine
            if (strstr(&oldLine[i], searchAr) == &oldLine[i])
            {
                wordCount++;
                // This tells us to go past the search argument we are at and go to the next character
                i += searchArlen;
            }
            else
            {
                i++;
            }
        }
        int sub_diff = replaceArlen - searchArlen;
        int after_length = oldLine_len;
        // Add the difference between the oldLine and newLine
        after_length += wordCount * sub_diff;

        // Allocate space for the newLine, accounting for the null terminator
        newLine = malloc((after_length + 1) * sizeof(char));
    }

    // Now we will loop through the oldLine and build the newLine
    long unsigned int i = 0;
    int j = 0;
    while (i < strlen(oldLine))
    {
        if (strstr(&oldLine[i], searchAr) == &oldLine[i])
        {
            // Replace the old substring with the new substring
            strcpy(&newLine[j], replaceAr);

            // Moves the i marker to the end of the old substring
            i += searchArlen;

            // Moves the j marker to the end of the new substring
            j += replaceArlen;
        }
        else
        {
            newLine[j] = oldLine[i];
            i++;
            j++;
        }
    }
    newLine[j] = '\0';
    return newLine;
}

char *prefixReplace(char *oldLine, char *searchArg, char *replaceArg) {
    int searchArlen = strlen(searchArg);
    int replaceArlen = strlen(replaceArg);
    int oldLine_len = strlen(oldLine);

    char *newLine;
    //Responsible for finding the difference in size of the strings and allocating space
    if (searchArlen == replaceArlen) {
        newLine = malloc((oldLine_len + 1) * sizeof(char));
    } else {
        int wordCount = 0;
        int i = 0;
        while (i < oldLine_len) {
            if (strstr(&oldLine[i], searchArg) == &oldLine[i]) {
                // Check if it's at the beginning of the line or preceded by punctuations/spaces
                if (i == 0 || is_punct_or_space(oldLine[i - 1])) {
                    wordCount++;
                    i += searchArlen;
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }
        int sub_diff = replaceArlen - searchArlen;
        int after_length = oldLine_len;
        after_length += wordCount * sub_diff;
        newLine = malloc((after_length + 1) * sizeof(char));
    }

    int i = 0;
    int j = 0;
    while (i < oldLine_len) {
        //If it finds the word in that line
        if (strstr(&oldLine[i], searchArg) == &oldLine[i]) {
            if ((i == 0 || is_punct_or_space(oldLine[i - 1]))) {
                strcpy(&newLine[j], replaceArg);
                j += replaceArlen;
                i += searchArlen;
                //Increment j until it finds a punctuation,space or end of line and add a space to newLine at that point
                while (!is_punct_or_space(oldLine[i]) && oldLine[i] != '\0') {

                    i++;
                }

            } else {
                newLine[j] = oldLine[i];
                i++;
                j++;
            }
        } else {
            newLine[j] = oldLine[i];
            i++;
            j++;
        }
    }
    newLine[j] = '\0';
    return newLine;
}
int main(int argc, char *argv[])
{

    if (argc < 7)
    {
        return MISSING_ARGUMENT;
    }
    // If there are duplicate arguments in argv, if there is more than one -s, -r, -l, or -w anywhere in argv, return 8
    int sCount = 0;
    int rCount = 0;
    int lCount = 0;
    int wCount = 0;
    //Our arguments 
    char *searchArg = NULL;
    char *replaceArg = NULL;
    long int lArg1Long = 0;
    long int lArg2Long = 0;
    //Flags and booleans to check if we have certain arguments
    int wFlag = 0;
    int sFlag = 0;
    int rFlag = 0;
    int wsFlag = 0;
    int lFlag=0;
    bool suffixSearch = false;
    bool prefixSearch = false;
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
            if (wsFlag == 1) {
                    if (searchArg[0] == '*') {
                        searchArg = &searchArg[1];
                        suffixSearch = true;
                    } else {
                        searchArg[strlen(searchArg) - 1] = '\0';
                        prefixSearch = true;
                    }
                }
            break;
        case 'r':
            rCount++;
            rFlag = 1;
            replaceArg = optarg;
            break;
        case 'l':
            lFlag=1;
            lCount++;
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
    // If we are unable to open the input file, return INPUT_FILE_MISSING
    FILE *inputFile = fopen(argv[argc - 2], "r");
    if (inputFile == NULL)
    {
        return INPUT_FILE_MISSING;
    }
    // If we are unable to open the output file, return OUTPUT_FILE_UNWRITABLE
    FILE *outputFile = fopen(argv[argc - 1], "w");
    if (outputFile == NULL)
    {
        return OUTPUT_FILE_UNWRITABLE;
    }

    // If the -s argument is missing, or the argument to -s is missing return S_ARGUMENT_MISSING
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
   
    for (int i = 1; i < argc - 2; i++)
    {
        if (strcmp(argv[i], "-l") == 0)
        { // If we find the -l flag
            // Check if the first character in argv[i+1] is a dash
            if (argv[i + 1][0] == '-')
            {
                return L_ARGUMENT_INVALID;
            }
            // Check if the argument to the -l flag does not contain a comma
            if (strchr(argv[i + 1], ',') == NULL)
            {
                return L_ARGUMENT_INVALID;
            }
            // Use strtok to separate the argument into two parts using the comma as a delimiter and then parse the two parts with strtol
            char *token = strtok(argv[i + 1], ",");
            // Check if the delimiter is missing
            if (token == NULL)
            {
                return L_ARGUMENT_INVALID;
            }
            char *endptr;
            lArg1Long = strtol(token, &endptr, 10);
            if (endptr == 0)
            {
                return L_ARGUMENT_INVALID;
            }
            // Parse the second part of the argument using strtol and check if it is missing or cannot be parsed
            token = strtok(NULL, ",");
            if (token == NULL)
            {
                return L_ARGUMENT_INVALID;
            }
            lArg2Long = strtol(token, &endptr, 10);
            // If strtol fails to parse the second part of the argument
            if (endptr == 0)
            {
                return L_ARGUMENT_INVALID;
            }
            // If the first l argument is greater than the second l argument, return 6
            if (lArg1Long > lArg2Long)
            {
                return L_ARGUMENT_INVALID;
            }
            if (lArg1Long < 1 || lArg2Long < 1)
            {
                return L_ARGUMENT_INVALID;
            }
        }
    }
    if (wsFlag == 0 && wFlag == 1)
    {
        return WILDCARD_INVALID;
    }
    //Goes through the lines of input file and based on args provided does a type of search&replace

    //If no lines were specified to read from, we read all lines of the file to check
   if (lFlag == 0) {
        //If we are doing a wildcard search
        if (wsFlag == 1 && wFlag == 1) {
            //If we are doing a prefix search
            if (prefixSearch) {
                char line[MAX_LINE];
                while (fgets(line, MAX_LINE, inputFile) != NULL) {
                    char *newLine = prefixReplace(line, searchArg, replaceArg);
                    // Copy the new line into the old line
                    strcpy(line, newLine);
                    free(newLine);

                    // Write the line to the output file
                    fprintf(outputFile, "%s", line);
                }
            }
            //If we are doing a suffix search
            if (suffixSearch) {
                char line[MAX_LINE];
                //int lineCount = 0;
                while (fgets(line, MAX_LINE, inputFile) != NULL) {
                    char *newLine = suffixReplace(line, searchArg, replaceArg);
                    // Copy the new line into the old line
                    strcpy(line, newLine);
                    free(newLine);

                    // Write the line to the output file
                    fprintf(outputFile, "%s", line);
                }
            }

        } else {
            //If we are not doing a wildcard search do a normal search&replace for all lines in file
            char line[MAX_LINE];
            while (fgets(line, MAX_LINE, inputFile) != NULL) {
                char *newLine = replace(line, searchArg, replaceArg);
                // Copy the new line into the old line
                strcpy(line, newLine);
                free(newLine);

                // Write the line to the output file
                fprintf(outputFile, "%s", line);
            }
        }
    } else {
        if (wsFlag == 1 && wFlag == 1) {
            if(prefixSearch){
                char line[MAX_LINE];
                int lineCount = 0;
                while (fgets(line, MAX_LINE, inputFile) != NULL) {
                    lineCount++;
                    // If the line is within the range of lines to be read
                    if (lineCount >= lArg1Long && lineCount <= lArg2Long) {
                        // Find and replace all occurrences of searchArg
                        char *newLine = prefixReplace(line, searchArg, replaceArg);
                        // Copy the new line into the old line
                        strcpy(line, newLine);
                        free(newLine);
                    }
                    // Write the line to the output file
                    fprintf(outputFile, "%s", line);
                }
            }
            if(suffixSearch){
                char line[MAX_LINE];
                int lineCount = 0;
                while (fgets(line, MAX_LINE, inputFile) != NULL) {
                    lineCount++;
                    // If the line is within the range of lines to be read
                    if (lineCount >= lArg1Long && lineCount <= lArg2Long) {
                        // Find and replace all occurrences of searchArg
                        char *newLine = suffixReplace(line, searchArg, replaceArg);
                        // Copy the new line into the old line
                        strcpy(line, newLine);
                        free(newLine);
                    }
                    // Write the line to the output file
                    fprintf(outputFile, "%s", line);
                }
            }

        } else {
            char line[MAX_LINE];
            int lineCount = 0;
            while (fgets(line, MAX_LINE, inputFile) != NULL) {
                lineCount++;
                // If the line is within the range of lines to be read
                if (lineCount >= lArg1Long && lineCount <= lArg2Long) {
                    // Find and replace all occurrences of searchArg
                    char *newLine = replace(line, searchArg, replaceArg);
                    // Copy the new line into the old line
                    strcpy(line, newLine);
                    free(newLine);
                }
                // Write the line to the output file
                fprintf(outputFile, "%s", line);
            }
        }
    }
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
