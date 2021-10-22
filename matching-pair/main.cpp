#include <iostream>
#include "../stack/stack.cpp"

const char openSymbols[] = {
    '(',
    '{',
    '[',
    '<',
};

const char closeSymbols[] = {
    ')',
    '}',
    ']',
    '>'
};

const char quoteSymbols[] = {
    '\'',
    '"',
    '`'
};

std::size_t getOpenIndex(char c) {
    for(std::size_t i = 0; i != (sizeof(openSymbols) / sizeof(char)); ++i) {
        if(openSymbols[i] == c) return i;
    }
    return -1;
}

std::size_t getCloseIndex(char c) {
    for(std::size_t i = 0; i != (sizeof(closeSymbols) / sizeof(char)); ++i) {
        if(closeSymbols[i] == c) return i;
    }
    return -1;
}

std::size_t getQuoteIndex(char c) {
    for(std::size_t i = 0; i != (sizeof(quoteSymbols) / sizeof(char)); ++i) {
        if(quoteSymbols[i] == c) return i;
    }
    return -1;
}

int main() {
    Stack<char>* pairs = new Stack<char>();
    std::string input;
    std::size_t idx;
    std::getline(std::cin, input);
    for(std::string::const_iterator it = input.cbegin(); it != input.cend(); ++it) {
        if((idx = getOpenIndex(*it)) != -1) {
            pairs->push(*it);
        } else if((idx = getCloseIndex(*it)) != -1) {
            if(pairs->top() != openSymbols[idx]) {
                pairs->push(*it);
                break;
            } else {
                pairs->pop();
            }
        } else if((idx = getQuoteIndex(*it)) != -1) {
            if(pairs->top() != quoteSymbols[idx]) {
                pairs->push(*it);
            } else {
                pairs->pop();
            }
        }
    }
    std::cout << (pairs->empty() ? "Matched!" : "Unmatched!") << std::ends;
    return 0;
}