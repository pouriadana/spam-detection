#include <cctype>
#include <cstdlib>
#include <format>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

void printContainer(std::vector<std::string> v);
void printContainer(const std::string& s);
void stringToLowerCase(std::string& s);
void toLowerCase(std::vector<std::string>& v);
int countWords(std::string s);

int main()
{
    // read the email message into a string with 
    std::string s;
    std::string message;
    while(std::getline(std::cin, s))
    {
        message += (s + "\n");
    }
    // std::cout << message[0] << '\n';
    // read spam words file and store in a vector
    std::vector<std::string> spam_list;
    if (std::ifstream spamlist_input{"spam_words.txt"})
    {
        std::string s;
        while (std::getline(spamlist_input, s))
        {
            spam_list.push_back(s);
        }
    }
    // TODO both email message and words list must be converted to lowercase
    stringToLowerCase(message);
    // printContainer(message);
    toLowerCase(spam_list);
    // printContainer(spam_list);

    int spam_score{0};
    for (const auto& item : spam_list)
    {
        size_t position{message.find(item)};
        while (position != std::string::npos)
        {
            ++spam_score;
            position = message.find(item, position + 1);
        }
    }
    std::cout << std::format("There are {} spam words in {} words of the message.\n", spam_score, countWords(message));
}

void printContainer(std::vector<std::string> v)
{
    for (const auto& item : v)
    {
        std::cout << item << '\n';
    }
}

void printContainer(const std::string& s)
{
    std::cout << s;
}

void stringToLowerCase(std::string& s)
{
    for (size_t index{0}; index < s.size(); ++index)
    {
        char lowercase = std::tolower(s[index]);
        s[index] = lowercase;
    }
}

void toLowerCase(std::vector<std::string>& v)
{
    for (size_t index{0}; index < v.size(); ++index)
    {
        stringToLowerCase(v[index]);
    }
}

int countWords(std::string s)
{
    std::smatch match;
    int count{0};
    while (std::regex_search(s, match, std::regex{"[A-Za-z]"}))
    {
        ++count;
        s = match.suffix();
    }
    return count;
}