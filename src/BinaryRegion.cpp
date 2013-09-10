#include "BinaryRegion.hpp"
#include <string.h>

BinaryRegion::BinaryRegion(const int64_t& base_address, const uint64_t& entry_point_offset, const char* content, size_t content_size)
	: m_baseAddress(base_address), m_entryPointOffset(entry_point_offset), m_content(NULL), m_contentSize(content_size)
{
	if(content == NULL) {
		m_content     = new char[1];
		m_contentSize = 0;
	} else {
		m_content = new char[m_contentSize];
		::memcpy(m_content, content, m_contentSize);
	}
}

BinaryRegion::~BinaryRegion() {
	freeResources();
}

BinaryRegion::BinaryRegion(const BinaryRegion& binaryRegion)
	: m_baseAddress(binaryRegion.m_baseAddress), m_entryPointOffset(binaryRegion.m_baseAddress),
	m_content(NULL), m_contentSize(binaryRegion.m_contentSize)
{
	if(binaryRegion.m_content == NULL) {
		m_content     = new char[1];
		m_contentSize = 0;
	} else {
		m_content = new char[m_contentSize];
		::memcpy(m_content, binaryRegion.m_content, m_contentSize);
	}
}

void BinaryRegion::freeResources() {
	delete[] m_content;
	m_content = NULL;
	m_contentSize = 0;
}

void BinaryRegion::setBaseAddress(const int64_t& base_address) {
	m_baseAddress = base_address;
}

void BinaryRegion::setEntryPointOffset(const uint64_t& entry_point_offset) {
	m_entryPointOffset = entry_point_offset;
}

void BinaryRegion::setContent(const char* content, size_t content_size) {
	freeResources();
	updateContent(content, content_size);
}

void BinaryRegion::updateContent(const char* content, size_t content_size) {
	m_content = new char[content_size];
	::memcpy(m_content, content, content_size);
	m_contentSize = content_size;
}