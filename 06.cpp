// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
#include <iostream>
#include <stack>

struct ListNode
{
	int       m_nValue;
	ListNode* m_pNext;
};

ListNode* CreateListNode(int value) {

	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = nullptr;

	return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext) {

	if (pCurrent == nullptr) {
		std::cout << "Error to connect two nodes." << std::endl;
		exit(1);
	}
	pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode) {

	if (pNode == nullptr) {
		std::cout << "The node is nullptr." << std::endl;
	}
	else {
		std::cout << pNode->m_nValue << std::endl;
	}
}

void PrintList(ListNode* pHead){

	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		std::cout << pNode->m_nValue << std::endl;
		pNode = pNode->m_pNext;
	}
}

void DestroyList(ListNode* pHead){

	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

void AddToTail(ListNode** pHead, int value) {

	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr) {
		*pHead = pNew;
	}
	else {
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr) {
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode** pHead, int value) {

	if (pHead == nullptr || *pHead == nullptr) {
		return;
	}
	ListNode* pToBeDeleted = nullptr;
	if ((*pHead)->m_nValue == value) {
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else {
		ListNode* pNode = *pHead;
		while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value) {
			pNode = pNode->m_pNext;
		}
		if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value) {
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	if (pToBeDeleted != nullptr) {
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

void PrintListReversingly_Iteratively(ListNode* pHead) {

	std::stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while (!nodes.empty()) {
		pNode = nodes.top();
		std::cout << pNode->m_nValue << std::endl;
		nodes.pop();
	}
}

void PrintListReversingly_Recursively(ListNode* pHead) {

	if (pHead != nullptr) {
		if (pHead->m_pNext != nullptr) {
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		std::cout << pHead->m_nValue << std::endl;
	}
}

// ====================测试代码====================
void Test(ListNode* pHead)
{
	PrintList(pHead);
	PrintListReversingly_Iteratively(pHead);
	printf("\n");
	PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void Test1()
{
	printf("\nTest1 begins.\n");

	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
	printf("\nTest2 begins.\n");

	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1);

	DestroyList(pNode1);
}

// 空链表
void Test3()
{
	printf("\nTest3 begins.\n");

	Test(nullptr);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();

	return 0;
}
