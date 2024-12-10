// part2.cpp
// code specific to part 2

#include "common.h"

namespace Part2
{
	class Section
	{
	public:
		Section(const int& id, const size_t& index, const size_t& size, bool empty)
		    :m_empty(empty)
	            , m_id(id)
		        , m_index(index)
		        , m_size(size)
		{
		}

		static void moveData(Section& src, Section& dst);

		[[nodiscard]] bool empty() const { return m_empty; }
		[[nodiscard]] size_t getSize() const { return m_size; }

		bool operator==(const Section&) const = default;

        unsigned long long calcChecksum() const;

	private:
		bool m_empty;
		int m_id;
		size_t m_index;
		size_t m_size;
	};

	void Section::moveData(Section& src, Section& dst)
	{
		src.m_index = dst.m_index;
		dst.m_size -= src.m_size;
		dst.m_index += src.m_size;
	}

    unsigned long long Section::calcChecksum() const
    {
		if (m_empty)
			return 0;

		unsigned long long checksum = 0;
		size_t index = m_index;
        for (int i = 0; i < m_size; ++i)
            checksum += m_id * index++;

		return checksum;
    }


	std::string run()
	{
		std::string condensedHardDrive = InputTaker::readAll();
		condensedHardDrive.pop_back();

		std::vector<Section> hardDrive;
		int id = 0;
		int index = 0;
		bool empty = false;

		for (const auto& c : condensedHardDrive)
		{
			const unsigned val = c - '0';
		    hardDrive.emplace_back(id, index, val, empty);

			index += val;

			if (!empty)
				++id;

			empty = !empty;
		}

		for (auto rit = hardDrive.rbegin(); rit != hardDrive.rend(); ++rit)
		{
		    if (!rit->empty()) // content that needs to be moved
		    {
		        for (auto it = hardDrive.begin(); *it != *rit; ++it)
		        {
		            if (it->empty() && it->getSize() >= rit->getSize()) // a space big enough for it to fit in
		            {
						Section::moveData(*rit, *it);
		                break;
		            }
		        }
		    }
		}

		unsigned long long sum = 0;
		for (auto& section : hardDrive)
			sum += section.calcChecksum();

		std::stringstream retStr;
		retStr << "the checksum is " << sum << std::endl;

		return retStr.str();
	}
}