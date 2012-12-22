#ifndef TRAINDATAPARSER_H
#define TRAINDATAPARSER_H

#include <string>
#include <fstream>

class WordNet;

class TrainDataParser
{
public:
	TrainDataParser();
	~TrainDataParser();

	bool read(const std::string &filePath);
	std::string errorString() const;
	WordNet *wordNet() const;

private:
	bool readWordNet();

	std::basic_ifstream<wchar_t> m_file;
	mutable std::string m_errorString;
	WordNet *m_wordNet;
};

#endif // TRAINDATAPARSER_H
