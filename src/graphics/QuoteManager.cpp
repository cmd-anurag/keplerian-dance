#include "graphics/QuoteManager.hpp"
#include <fstream>
#include <random>
#include <iostream>
#include <ctime>

QuoteManager::QuoteManager(const std::string& filename)
{
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
    loadQuotes(filename);
}

void QuoteManager::loadQuotes(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open quote file: " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            m_quotes.push_back(line);
        }
    }
}

const std::string& QuoteManager::getRandomQuote()
{
    if (m_quotes.empty()) {
        return m_emptyQuote;
    }
    int randomIndex = rand() % m_quotes.size();
    return m_quotes[randomIndex];
}