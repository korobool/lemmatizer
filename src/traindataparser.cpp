#include <iostream>
#include <algorithm>
#include "traindataparser.h"
#include "wordnet.h"

TrainDataParser::TrainDataParser()
{
}

TrainDataParser::~TrainDataParser()
{
}

bool TrainDataParser::read(const std::string &filePath)
{
	m_wordNet = new WordNet;

	m_file.open(filePath, std::ios_base::in);

	if (!m_file.good()) {
		m_errorString = "Open file error: probably file doesn't exist";
		m_file.close();
		delete m_wordNet;
		return false;
	}

	if (!(readWordNet())) {
		m_file.close();
		delete m_wordNet;
		return false;
	}

	m_file.close();
	return true;
}

WordNet *TrainDataParser::wordNet() const
{
	return m_wordNet;
}

std::string TrainDataParser::errorString() const
{
	return m_errorString;
}

/* private */

bool TrainDataParser::readWordNet()
{
	const wchar_t delimeter = u',';

	while (!m_file.eof() && m_file.good()) {
		std::wstring line;
		std::getline(m_file, line);
		std::wstring::iterator delimIt = std::find(line.begin(), line.end(), delimeter);
		if (delimIt == line.end())
			continue;
		
		std::wstring word(line.begin(), delimIt);
		std::wstring lemma(delimIt + 1, line.end());
		
		bool badLine = std::find(lemma.begin(), lemma.end(), delimeter) != lemma.end();
		if (word.empty() || lemma.empty() || badLine) {
			std::wcerr << u"Bad line: " << line << std::endl;
			continue;
		}
		
		m_wordNet->addString(word, lemma);
	}
	
	return true;
}
