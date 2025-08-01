#pragma once
#include <vector>
#include <string>

class QuoteManager
{
public:
    QuoteManager(const std::string& filename);
    const std::string& getRandomQuote();

private:
    void loadQuotes(const std::string& filename);
    std::vector<std::string> m_quotes;
    std::string m_emptyQuote = "Loading...";
};