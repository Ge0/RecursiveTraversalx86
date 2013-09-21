#ifndef _BINARY_REGION_HPP_
#define _BINARY_REGION_HPP_


#include <stdio.h>
#include <cstdint>

namespace RecursiveTraversal {

	class BinaryRegion {
	public:
		BinaryRegion(const int64_t& = 0, const uint64_t& = 0, const char* = NULL, size_t = 0);
		virtual ~BinaryRegion();
		BinaryRegion(const BinaryRegion&);
		
		inline const int64_t& baseAddress() const {
			return m_baseAddress;
		}
		
		inline const uint64_t& entryPointOffset() const {
			return m_entryPointOffset;
		}
		
		inline char* const content() const {
			return m_content;
		}
		
		inline size_t contentSize() const {
			return m_contentSize;
		}
		
		void setBaseAddress(const int64_t& address);
		void setEntryPointOffset(const uint64_t& entry_point_offset);
		void setContent(const char* content, size_t content_size);
<<<<<<< HEAD
		bool hasAddress(const int64_t& address) const; 
=======
<<<<<<< HEAD
=======
		bool hasAddress(const int64_t& address) const; 
>>>>>>> origin/Ge0
>>>>>>> dcc8ea13477788d040e73151effc66035508c838
		
	private:
		/* Private methods */
		void freeResources();
		void updateContent(const char* content, size_t content_size);
		
		/* Attributes */
		int64_t m_baseAddress;
		uint64_t m_entryPointOffset;
		char* m_content;
		size_t m_contentSize;
	};
}

#endif /* _BINARY_REGION_HPP_ */