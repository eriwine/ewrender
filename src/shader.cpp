#include "ew/shader.hpp"
#include <glad/glad.h>
#include <stdio.h>

ew::Shader::Shader() {
	m_programHandle = glCreateProgram();
}

void ew::Shader::compileStage(ShaderStage stage, const char* source)
{
	GLenum glShaderType = GL_VERTEX_SHADER;
	const char* shaderTypeName;

	switch (stage) {
	default:
	case ShaderStage::VERTEX:
		glShaderType = GL_VERTEX_SHADER;
		shaderTypeName = "VERTEX";
		break;
	case ShaderStage::FRAGMENT:
		glShaderType = GL_FRAGMENT_SHADER;
		shaderTypeName = "FRAGMENT";
		break;
	}

	if (m_handles.find(stage) == m_handles.end()) {
		m_handles[stage] = glCreateShader(glShaderType);
		glAttachShader(m_programHandle,m_handles[stage]);
	}
	unsigned int shader = m_handles[stage];
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		char buffer[512];
		int length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		glGetShaderInfoLog(shader, sizeof(char) * 512, &length, buffer);
		printf("FAILED TO COMPILE %s SHADER %s", shaderTypeName, buffer);
		return;
	}
}

void ew::Shader::link() {
	glLinkProgram(m_programHandle);
	int success;
	glGetProgramiv(m_programHandle, GL_LINK_STATUS, &success);
	if (!success) {
		char buffer[512];
		int length;
		glGetProgramiv(m_programHandle, GL_INFO_LOG_LENGTH, &length);
		glGetProgramInfoLog(m_programHandle, sizeof(char) * 512, &length, buffer);
		printf("FAILED TO LINK SHADER PROGRAM %s", buffer);
	}
}

void ew::Shader::use() {
	glUseProgram(m_programHandle);
}