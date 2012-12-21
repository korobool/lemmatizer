#include <iostream>
#include "wordnode.h"

WordNode::WordNode()
{
}

WordNode::~WordNode()
{
	// TODO: remove the whole underlaying structure
}

void WordNode::addString(const std::wstring &s, const std::wstring *lemma)
{
	WordNodeMap::iterator tmpIt;
	WordNode *curNode = this;

	if (!s.length())
		return;

	for (std::wstring::const_iterator it = s.cbegin(); it != s.cend(); ++it) {
		// BUG: remove this check after fixing input data issue
		if (!*it) {
			std::cerr << "fack!" << std::endl;
			return;
		} else {
			std::wcout << u"received: " << *it << std::endl;
		}
		
		tmpIt = curNode->m_map.find(*it);
		if (tmpIt == curNode->m_map.end()) { // node already exists
			curNode = tmpIt->second;
		} else {
			WordNode *tmpNode = new WordNode;
			curNode->m_map[*it] = tmpNode;
			curNode = tmpNode;
		}
	}

	// Since we know that this is lemma (LemmaChar) -- cast it to string
	curNode->m_map[LemmaChar] =
			reinterpret_cast<WordNode*>(const_cast<std::wstring*>(lemma));
}
