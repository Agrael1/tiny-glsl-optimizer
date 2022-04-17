#include <optimizer/optimizer.h>
#include <code/GlslConvert.h>



std::string Optimize(std::string vShaderSource, xShaderStage vShaderType, int vGLSLVersion)
{
	GlslConvert::OptimizationStruct os;
	//os.optimizationFlags_Bis = GlslConvert::OptimizationFlags_Bis(0);
	//os.optimizationFlags = GlslConvert::OptimizationFlags(0);


	return GlslConvert::Instance()->Optimize(vShaderSource, GlslConvert::ShaderStage(vShaderType), GlslConvert::API_OPENGL_COMPAT, GlslConvert::LanguageTarget::LANGUAGE_TARGET_GLSL, vGLSLVersion, os);
}