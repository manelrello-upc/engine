#pragma once
#include "render/Material.h"
#include "render/RenderResource.h"
#include "GPUResourceOpenGL.h"

namespace engine
{
	struct GPUResourceMaterialOpenGLParams
	{
		std::optional<std::string> vertexShaderCode;
		std::optional<std::string> fragmentShaderCode;
	};

	class SpirVCompiler;
	class GPUResourceMaterialOpenGL : public GPUResourceOpenGL
	{
	public:
		GPUResourceMaterialOpenGL(const GPUResourceMaterialOpenGLParams& i_params, const SpirVCompiler& i_compiler);
		GPUResourceMaterialOpenGL(GPUResourceMaterialOpenGL&& i_other);
		~GPUResourceMaterialOpenGL();

		void Use();

	private:

		GLuint m_programId = std::numeric_limits<GLuint>::max();
	};
}