#pragma once

#include <fstream>

namespace engine
{
	template<typename AssetType>
	class Asset: public Asset<void>
	{
	public:
		Asset(std::string i_path, AssetType i_assetData)
			: Asset<void>(std::move(i_path))
			, m_asset(std::move(i_assetData))
		{
			std::ifstream file(i_path);
			assert(file.is_open());
			std::ostringstream ss;
			ss << file.rdbuf();
			m_data = ss.str();
			file.close();
		}


		inline const AssetType& GetAsset() const
		{
			return m_asset;
		}

		inline std::optional<std::string> GetData() const
		{
			return *m_data;
			//if (m_data.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
			//{
			//	return *m_data;
			//}
			//else
			//{
			//	return std::nullopt;
			//}
		}

	private:
		AssetType m_asset;
		//std::optional<std::vector<char>> m_data;
		std::optional<std::string> m_data;
	};

	template<>
	class Asset<void>
	{
	public:
		Asset(std::filesystem::path i_path)
			: m_path(std::move(i_path))
		{

		}

		inline const std::filesystem::path& GetPath() const
		{
			return m_path;
		}

	private:
		std::filesystem::path m_path;
	};

}