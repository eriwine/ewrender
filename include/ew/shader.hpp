#pragma once
#include <map>

namespace ew {
	enum ShaderStage {
		NONE = 0,
		VERTEX, FRAGMENT
	};
	class Shader {
	public:
		Shader();
		void compileStage(ShaderStage stage, const char* source);
		void link();
		void use();
	private:
		unsigned int m_programHandle;
		std::map<ShaderStage, unsigned int> m_handles;
	};
}