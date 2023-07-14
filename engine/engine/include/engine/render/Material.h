#pragma once
#include "Resource.h"
#include "RenderResource.h"
#include "engine/db/ShaderAsset.h"

namespace engine
{
	class ShaderAssetVertex;
	class ShaderAssetFragment;


	class MaterialGeneric: public Resource, public RenderResource<MaterialGeneric>
	{
	public:
		~MaterialGeneric();
		
		const std::optional<std::string> GetVertexShaderCode() const;
		const std::optional<std::string> GetFragmentShaderCode() const;

		enum class LoadResult
		{
			Success,
			Failed
		};
		//static std::future<LoadResult> Load(const MaterialGeneric& i_material, const Context& i_engineContext);
		//static std::future<LoadResult> LoadData(const MaterialGeneric& i_material, const Context& i_engineContext);
		//static std::future<LoadResult> LoadVisual(const MaterialGeneric& i_material, const Context& i_engineContext);


	protected:
		MaterialGeneric(std::shared_ptr<Asset<ShaderAssetVertex>> i_vertexShader, std::shared_ptr<Asset<ShaderAssetFragment>> i_fragmentShader);

	private:
		std::shared_ptr<Asset<ShaderAssetVertex>> m_vertexShader; 
		std::shared_ptr<Asset<ShaderAssetFragment>> m_fragmentShader;
	};

	template<typename Layout>
	class Material : public MaterialGeneric
	{
	public:
		inline Material(std::shared_ptr<Asset<ShaderAssetVertex>> i_vertexShader, std::shared_ptr<Asset<ShaderAssetFragment>> i_fragmentShader)
			: MaterialGeneric(std::move(i_vertexShader), std::move(i_fragmentShader))
		{

		}
	};
}