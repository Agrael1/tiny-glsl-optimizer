#include <optimizer/optimizer.h>
#include <code/GlslConvert.h>



std::string Optimize(std::string vShaderSource, xShaderStage vShaderType, int vGLSLVersion)
{
	return GlslConvert::Instance()->Optimize(vShaderSource, GlslConvert::ShaderStage(vShaderType), GlslConvert::API_OPENGL_COMPAT, GlslConvert::LanguageTarget::LANGUAGE_TARGET_GLSL, vGLSLVersion, {});
}