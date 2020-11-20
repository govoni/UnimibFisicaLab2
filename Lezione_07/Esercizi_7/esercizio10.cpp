/*
c++ -o es10 esercizio10.cpp

Testo:
    Si crei una std::string riempita con un periodo scelto a piacere.

    Si contino il numero di parole ed il numero di lettere (spazi esclusi) che compongono il periodo.
    Si divida la stringa in singole parole, ciascuna salvata con una stringa all'interno di un std::vector.
*/
#include <string>
#include <iostream>
#include <vector>

int count_words(std::string const& s){
    bool literal = false;
    int n_words = 0;

    if(s.empty()) return 0;

    std::string::const_iterator it = s.begin();

    do{
        if(*it != ' '){ //char of a word
            ++it;
            literal = true;
        }
        else if (*it == ' ' && literal) { //end of word
            ++it;
            ++n_words;
            literal = false;
        }

        else ++it; //double spaces
        
    }
    while(it != s.end());

    if (literal) ++n_words; //case where s = "abcd" (no spaces but literals)

    return n_words;

}

std::vector<std::string>&  fill_vec(std::vector<std::string>& v, std::string const& s){
    
    if(s.empty()) return v;
    bool literal = false;

    std::string word;
    std::string::const_iterator it = s.begin();

    
    do{
        if(*it != ' '){ //char of a word
            word.push_back(*it);
            ++it;
            literal = true;
        }
        
        else if (*it == ' ' && literal) { //end of word
            v.push_back(word);
            word.clear();
            ++it;
            literal = false;
        }
        
        else ++it; //double spaces


    }while(it != s.end());

    v.push_back(word);
    
    return v;
}

int count_letters(std::string const& s){
    int l_c = 0;
    if(s.empty()) return 0;

    std::string::const_iterator it = s.begin();

    do{
        if(*it != ' ') ++l_c;
        ++it; 
    }
    while(it != s.end());

    return l_c;

}



int main(){

    std::string Lorem_Ipsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "   
                            "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
                            "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris "
                            "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in " 
                            "reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla " 
                            "pariatur. Excepteur sint occaecat cupidatat non proident, sunt in " 
                            "culpa qui officia deserunt mollit anim id est laborum.";

    std::cout << "Words: " << count_words(Lorem_Ipsum) << std::endl;
    std::cout << "Char: " << count_letters(Lorem_Ipsum) << std::endl;

    std::string hw = "Hello world!";
    std::cout << "Words: " << count_words(hw) << std::endl;
    std::cout << "Char: " << count_letters(hw) << std::endl;

    hw = "Hello                    world!";
    std::cout << "Words: " << count_words(hw) << std::endl;
    std::cout << "Char: " << count_letters(hw) << std::endl;

    std::vector<std::string> v;
    v = fill_vec(v, Lorem_Ipsum);
    for (std::vector<std::string>::iterator it = v.begin() ; it != v.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Number of words: " << v.size() << std::endl;

    hw = " ";
    std::cout << "Words: " << count_words(hw) << std::endl;
    std::cout << "Char: " << count_letters(hw) << std::endl;
    
    return 0;
}