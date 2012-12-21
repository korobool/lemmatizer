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

	for (auto c : s) {
		tmpIt = curNode->m_map.find(c);
#if 0
		if (tmpIt == curNode->m_map.end()) { // node already exists
			curNode = tmpIt->second;
		} else {
			WordNode *tmpNode = new WordNode;
			curNode->m_map[*it] = tmpNode;
			curNode = tmpNode;
		}
#endif
	}
#if 0
	// Since we know that this is lemma (LemmaChar) -- cast it to string
	curNode->m_map[LemmaChar] =
			reinterpret_cast<WordNode*>(const_cast<std::wstring*>(lemma));
#endif
}
