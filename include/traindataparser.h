#ifndef TRAINDATAPARSER_H
#define TRAINDATAPARSER_H

#include <string>

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

	WordNet *m_wordNet;
};

#endif // TRAINDATAPARSER_H
