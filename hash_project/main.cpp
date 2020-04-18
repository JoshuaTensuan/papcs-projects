#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <cmath>
// using namespace std;


// trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        std::cout << "Incorrect args" << std::endl;
    } else {
        auto m_StartTime = std::chrono::system_clock::now();

        std::string line;
        std::ifstream myfile;
        myfile.open(argv[1]);
        std::unordered_map<std::string, int> umap; 
        if (myfile.is_open()) { // go through keyword file
            while (getline(myfile, line)) {
                line = trim(line);
                std::string kwline = line;
                auto c3 = line.find("#"); // comment handling
                if(c3 != std::string::npos) {
                    kwline = line.substr(0, c3);
                    
                }
                kwline = trim(kwline); // remove spaces from before and after
                if(kwline != "") {
                    for (int i = 0, len = kwline.size(); i < len; i++) { 
                        // check whether parsing character is punctuation or not 
                        if (ispunct(kwline[i])) { 
                            kwline.erase(i--, 1); 
                            len = kwline.size(); 
                        } 
                    } 
                    std::for_each(kwline.begin(), kwline.end(), [](char & d){ // change everything to lower case
                    d = ::tolower(d);
                });
                    umap[kwline] = 0;
                }
            }
        myfile.close();
        } else {
            std::cout << "Unable to open keyword file" << std::endl; 
        }

        std::ifstream ifile;
        ifile.open(argv[2]);
        int num_words = 0;
        int num_keywords = 0;
        int num_lines = 0;
        int index = 0;
        if (ifile.is_open()) { // go through textfile

            while(std::getline(ifile, line)) {
                std::string aline = trim(line); // remove spaces
                std::for_each(aline.begin(), aline.end(), [](char & c){ // make everything lower case
                    c = ::tolower(c);
                });
                if(aline != "") {
                    ++num_lines;
                    int x = aline.find(' ');
                    while (x != std::string::npos) { // in each line, split words by space
                        std::string temp = aline.substr(0, x);
                        ++num_words;    
                        for (int i = 0, len = temp.size(); i < len; i++) {  // remove punctuation
                            if (ispunct(temp[i])) { 
                                temp.erase(i--, 1); 
                                len = temp.size(); 
                            } 
                        } 
                        std::unordered_map<std::string,int>::const_iterator it = umap.find (temp);
                        if(it == umap.end()) {
                            // std::cout << "not found" << std::endl;
                        } else {
                            ++num_keywords;
                            umap[it -> first] = it -> second + 1; // increment value in hash table
                        }
                        std::string temp2 = aline.substr(x);
                        aline = trim(temp2);
                        x = aline.find(' '); // does this until very last word
                    }
                    for (int i = 0, len = aline.size(); i < len; i++) {  // again remove punctuation from very last word
                        if (ispunct(aline[i])) { 
                            aline.erase(i--, 1); 
                            len = aline.size(); 
                        } 
                    } 
                    std::unordered_map<std::string,int>::const_iterator it = umap.find (aline);
                    ++num_words;
                    if(it == umap.end()) {
                        // std::cout << "not found" << std::endl;
                    } else {
                        ++num_keywords;
                        umap[it -> first] = it -> second + 1; // increment value in hash table
                    }
                } 
            }
        } else {
            std::cout << "Unable to open text file" << std::endl; 
        }
        ifile.close();

        auto m_EndTime = std::chrono::system_clock::now();
        auto time_elapsed = m_EndTime - m_StartTime;

        std::cout << "**********************" << std::endl;
        std::cout << "***** Statistics *****" << std::endl;
        std::cout << "**********************" << std::endl;

        std::cout << "Total Lines Read: " << num_lines << std::endl;
        std::cout << "Total Words Read: " << num_words << std::endl;
        std::cout << "Total Keywords Read: " << num_keywords << std::endl;
        std::cout << "Breakdown by Keyword: " << std::endl << "\t";
        
        std::unordered_map<std::string, int>::iterator iter = umap.begin();
        while(iter != umap.end()) {
            std::cout << iter -> first << ": "<< iter -> second << std::endl << "\t";
            iter++;
        }

        std::cout << std::endl;
        std::cout << "Time Elapsed: " << time_elapsed.count()/(float) (pow(10,9)) << " seconds" << std::endl; // fix data type
    }
}