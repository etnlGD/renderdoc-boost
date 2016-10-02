#pragma once
#include <map>
#include <d3d11.h>
#include "Log.h"

namespace rdcboost
{
	class PrivateDataMap
	{
	public:
		struct SPrivateData
		{
			UINT m_DataSize;
			void* m_pData;
			
			SPrivateData() : m_DataSize(0), m_pData(NULL)
			{
			}

			SPrivateData(UINT DataSize, const void* pData) : 
				m_DataSize(DataSize), m_pData(new char[DataSize])
			{
				memcpy(m_pData, pData, DataSize);
			}

			~SPrivateData()
			{
				delete[] m_pData;
			}

			SPrivateData(const SPrivateData& rhs) : 
				m_DataSize(rhs.m_DataSize), m_pData(new char[rhs.m_DataSize])
			{
				memcpy(m_pData, rhs.m_pData, rhs.m_DataSize);
			}

			SPrivateData& operator=(const SPrivateData& rhs)
			{
				delete[] m_pData;
				m_DataSize = rhs.m_DataSize;
				m_pData = new char[m_DataSize];
				memcpy(m_pData, rhs.m_pData, m_DataSize);
				return *this;
			}
		};

		~PrivateDataMap()
		{
			for (auto it = m_PrivateInterfaces.begin(); it != m_PrivateInterfaces.end(); ++it)
				const_cast<IUnknown*>(it->second)->Release();
		}

		void SetPrivateData(REFGUID guid, UINT DataSize, const void *pData)
		{
			if (DataSize == 0 || pData == NULL)
			{
				m_PrivateDatas.erase(guid);
			}
			else
			{
				m_PrivateDatas[guid] = SPrivateData(DataSize, pData);
			}
		}

		void SetPrivateDataInterface(REFGUID guid, const IUnknown *pData)
		{
			auto it = m_PrivateInterfaces.find(guid);
			if (pData != NULL)
			{
				const_cast<IUnknown*>(pData)->AddRef();
				if (it != m_PrivateInterfaces.end())
				{
					const_cast<IUnknown*>(it->second)->Release();
					it->second = pData;
				}
				else
				{
					m_PrivateInterfaces.insert(std::make_pair(guid, pData));
				}
			}
			else
			{
				if (it != m_PrivateInterfaces.end())
				{
					const_cast<IUnknown*>(it->second)->Release();
					m_PrivateInterfaces.erase(it);
				}
			}
		}

		template <typename T>
		void CopyPrivateData(T* pObject)
		{
			for (auto it = m_PrivateDatas.begin(); it != m_PrivateDatas.end(); ++it)
			{
				pObject->SetPrivateData(it->first, it->second.m_DataSize, it->second.m_pData);
			}

			for (auto it = m_PrivateInterfaces.begin(); it != m_PrivateInterfaces.end(); ++it)
			{
				pObject->SetPrivateDataInterface(it->first, it->second);
			}
		}

	private:
		template <typename T>
		class less_memcmp
		{
		public:
			bool operator()(const T& lhs, const T& rhs) const
			{
				return memcmp(&lhs, &rhs, sizeof(T)) < 0;
			}
		};
		std::map<GUID, SPrivateData, less_memcmp<GUID> > m_PrivateDatas;
		std::map<GUID, const IUnknown*, less_memcmp<GUID> > m_PrivateInterfaces;
	};
}

