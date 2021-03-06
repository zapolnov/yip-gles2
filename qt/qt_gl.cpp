/* vim: set ai noet ts=4 sw=4 tw=115: */
//
// Copyright (c) 2014 Nikolay Zapolnov (zapolnov@gmail.com).
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
#include "../gl.h"
#include "../gl_error.h"
#include <QGLContext>
#include <QGLFunctions>
#include <cassert>
#include <thread>

static QGLFunctions g_OpenGLFunctions;
static std::once_flag g_Init;

void GL::init()
{
	std::call_once(g_Init, [](){
		g_OpenGLFunctions.initializeGLFunctions();
	});
}

void GL::activeTexture(Enum texture)
{
	g_OpenGLFunctions.glActiveTexture(texture);
	CHECK_GL_ERROR1(glActiveTexture, texture);
}

void GL::attachShader(UInt program, UInt shader)
{
	g_OpenGLFunctions.glAttachShader(program, shader);
	CHECK_GL_ERROR2(glAttachShader, program, shader);
}

void GL::bindAttribLocation(UInt program, UInt index, const Char * name)
{
	g_OpenGLFunctions.glBindAttribLocation(program, index, name);
	CHECK_GL_ERROR3(glBindAttribLocation, program, index, name);
}

void GL::bindBuffer(Enum target, UInt buffer)
{
	g_OpenGLFunctions.glBindBuffer(target, buffer);
	CHECK_GL_ERROR2(glBindBuffer, target, buffer);
}

void GL::bindFramebuffer(Enum target, UInt framebuffer)
{
	g_OpenGLFunctions.glBindFramebuffer(target, framebuffer);
	CHECK_GL_ERROR2(glBindFramebuffer, target, framebuffer);
}

void GL::bindRenderbuffer(Enum target, UInt renderbuffer)
{
	g_OpenGLFunctions.glBindRenderbuffer(target, renderbuffer);
	CHECK_GL_ERROR2(glBindRenderbuffer, target, renderbuffer);
}

void GL::bindTexture(Enum target, UInt texture)
{
	glBindTexture(target, texture);
	CHECK_GL_ERROR2(glBindTexture, target, texture);
}

void GL::blendColor(Clampf red, Clampf green, Clampf blue, Clampf alpha)
{
	g_OpenGLFunctions.glBlendColor(red, green, blue, alpha);
	CHECK_GL_ERROR4(glBlendColor, red, green, blue, alpha);
}

void GL::blendEquation(Enum mode)
{
	g_OpenGLFunctions.glBlendEquation(mode);
	CHECK_GL_ERROR1(glBlendEquation, mode);
}

void GL::blendEquationSeparate(Enum modeRGB, Enum modeAlpha)
{
	g_OpenGLFunctions.glBlendEquationSeparate(modeRGB, modeAlpha);
	CHECK_GL_ERROR2(glBlendEquationSeparate, modeRGB, modeAlpha);
}

void GL::blendFunc(Enum sfactor, Enum dfactor)
{
	glBlendFunc(sfactor, dfactor);
	CHECK_GL_ERROR2(glBlendFunc, sfactor, dfactor);
}

void GL::blendFuncSeparate(Enum srcRGB, Enum dstRGB, Enum srcAlpha, Enum dstAlpha)
{
	g_OpenGLFunctions.glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
	CHECK_GL_ERROR4(glBlendFunc, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void GL::bufferData(Enum target, Sizeiptr size, const void * data, Enum usage)
{
	g_OpenGLFunctions.glBufferData(target, size, data, usage);
	CHECK_GL_ERROR4(glBufferData, target, size, data, usage);
}

void GL::bufferSubData(Enum target, Intptr offset, Sizeiptr size, const void * data)
{
	g_OpenGLFunctions.glBufferSubData(target, offset, size, data);
	CHECK_GL_ERROR4(glBufferSubData, target, offset, size, data);
}

GL::Enum GL::checkFramebufferStatus(Enum target)
{
	GLenum status = g_OpenGLFunctions.glCheckFramebufferStatus(target);
	CHECK_GL_ERROR1(glCheckFramebufferStatus, target);
	return static_cast<GL::Enum>(status);
}

void GL::clear(Bitfield mask)
{
	glClear(mask);
	CHECK_GLCLEAR_ERROR(glClear, mask);
}

void GL::clearColor(Clampf red, Clampf green, Clampf blue, Clampf alpha)
{
	glClearColor(red, green, blue, alpha);
	CHECK_GL_ERROR4(glClearColor, red, green, blue, alpha);
}

void GL::clearDepthf(Clampf depth)
{
	g_OpenGLFunctions.glClearDepthf(depth);
	CHECK_GL_ERROR1(glClearDepth, depth);
}

void GL::clearStencil(Int s)
{
	glClearStencil(s);
	CHECK_GL_ERROR1(glClearStencil, s);
}

void GL::colorMask(Boolean red, Boolean green, Boolean blue, Boolean alpha)
{
	glColorMask(red, green, blue, alpha);
	CHECK_GL_ERROR4(glColorMask, red, green, blue, alpha);
}

void GL::compileShader(UInt shader)
{
	g_OpenGLFunctions.glCompileShader(shader);
	CHECK_GL_ERROR1(glCompileShader, shader);
}

void GL::compressedTexImage2D(Enum target, Int level, Enum internalformat, Sizei width, Sizei height,
	Int border, Sizei imageSize, const void * data)
{
	g_OpenGLFunctions.glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
	CHECK_GL_ERROR8(glCompressedTexImage2D, target, level, internalformat, width, height, border, imageSize, data);
}

void GL::compressedTexSubImage2D(Enum target, Int level, Int xoffset, Int yoffset, Sizei width,
	Sizei height, Enum format, Sizei imageSize, const void * data)
{
	g_OpenGLFunctions.glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
	CHECK_GL_ERROR9(glCompressedTexSubImage2D, target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void GL::copyTexImage2D(Enum target, Int level, Enum intfmt, Int x, Int y, Sizei w, Sizei h, Int border)
{
	glCopyTexImage2D(target, level, intfmt, x, y, w, h, border);
	CHECK_GL_ERROR8(glCopyTexImage2D, target, level, intfmt, x, y, w, h, border);
}

void GL::copyTexSubImage2D(Enum target, Int level, Int xoff, Int yoff, Int x, Int y, Sizei w, Sizei h)
{
	glCopyTexSubImage2D(target, level, xoff, yoff, x, y, w, h);
	CHECK_GL_ERROR8(glCopyTexSubImage2D, target, level, xoff, yoff, x, y, w, h);
}

GL::UInt GL::createProgram()
{
	GL::UInt handle = g_OpenGLFunctions.glCreateProgram();
	CHECK_GL_ERROR0(glCreateProgram);
	return handle;
}

GL::UInt GL::createShader(Enum type)
{
	GL::UInt handle = g_OpenGLFunctions.glCreateShader(type);
	CHECK_GL_ERROR1(glCreateShader, type);
	return handle;
}

void GL::cullFace(Enum mode)
{
	glCullFace(mode);
	CHECK_GL_ERROR1(glCullFace, mode);
}

void GL::deleteBuffers(Sizei n, const UInt * buffers)
{
	g_OpenGLFunctions.glDeleteBuffers(n, buffers);
	CHECK_GL_ERROR2(glDeleteBuffers, n, buffers);
}

void GL::deleteFramebuffers(Sizei n, const UInt * framebuffers)
{
	g_OpenGLFunctions.glDeleteFramebuffers(n, framebuffers);
	CHECK_GL_ERROR2(glDeleteFramebuffers, n, framebuffers);
}

void GL::deleteProgram(UInt program)
{
	g_OpenGLFunctions.glDeleteProgram(program);
	CHECK_GL_ERROR1(glDeleteProgram, program);
}

void GL::deleteRenderbuffers(Sizei n, const UInt * renderbuffers)
{
	g_OpenGLFunctions.glDeleteRenderbuffers(n, renderbuffers);
	CHECK_GL_ERROR2(glDeleteRenderbuffers, n, renderbuffers);
}

void GL::deleteShader(UInt shader)
{
	g_OpenGLFunctions.glDeleteShader(shader);
	CHECK_GL_ERROR1(glDeleteShader, shader);
}

void GL::deleteTextures(Sizei n, const UInt * textures)
{
	glDeleteTextures(n, textures);
	CHECK_GL_ERROR2(glDeleteTextures, n, textures);
}

void GL::depthFunc(Enum func)
{
	glDepthFunc(func);
	CHECK_GL_ERROR1(glDepthFunc, func);
}

void GL::depthMask(Boolean flag)
{
	glDepthMask(flag);
	CHECK_GL_ERROR1(glDepthMask, flag);
}

void GL::depthRangef(Clampf zNear, Clampf zFar)
{
	g_OpenGLFunctions.glDepthRangef(zNear, zFar);
	CHECK_GL_ERROR2(glDepthRangef, zNear, zFar);
}

void GL::detachShader(UInt program, UInt shader)
{
	g_OpenGLFunctions.glDetachShader(program, shader);
	CHECK_GL_ERROR2(glDetachShader, program, shader);
}

void GL::disable(Enum cap)
{
	glDisable(cap);
	CHECK_GL_ERROR1(glDisable, cap);
}

void GL::disableVertexAttribArray(UInt index)
{
	g_OpenGLFunctions.glDisableVertexAttribArray(index);
	CHECK_GL_ERROR1(glDisableVertexAttribArray, index);
}

void GL::drawArrays(Enum mode, Int first, Sizei count)
{
	glDrawArrays(mode, first, count);
	CHECK_GL_ERROR3(glDrawArray, mode, first, count);
}

void GL::drawElements(Enum mode, Sizei count, Enum type, const void * indices)
{
	glDrawElements(mode, count, type, indices);
	CHECK_GL_ERROR4(glDrawElements, mode, count, type, indices);
}

void GL::enable(Enum cap)
{
	glEnable(cap);
	CHECK_GL_ERROR1(glEnable, cap);
}

void GL::enableVertexAttribArray(UInt index)
{
	g_OpenGLFunctions.glEnableVertexAttribArray(index);
	CHECK_GL_ERROR1(glEnableVertexAttribArray, index);
}

void GL::finish()
{
	glFinish();
	CHECK_GL_ERROR0(glFinish);
}

void GL::flush()
{
	glFlush();
	CHECK_GL_ERROR0(glFlush);
}

void GL::framebufferRenderbuffer(Enum target, Enum attachment, Enum renderbuffertarget, UInt renderbuffer)
{
	g_OpenGLFunctions.glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
	CHECK_GL_ERROR4(glFramebufferRenderbuffer, target, attachment, renderbuffertarget, renderbuffer);
}

void GL::framebufferTexture2D(Enum target, Enum attachment, Enum textarget, UInt texture, Int level)
{
	g_OpenGLFunctions.glFramebufferTexture2D(target, attachment, textarget, texture, level);
	CHECK_GL_ERROR5(glFramebufferTexture2D, target, attachment, textarget, texture, level);
}

void GL::frontFace(Enum mode)
{
	glFrontFace(mode);
	CHECK_GL_ERROR1(glFrontFace, mode);
}

void GL::genBuffers(Sizei n, UInt * buffers)
{
	g_OpenGLFunctions.glGenBuffers(n, buffers);
	CHECK_GL_ERROR2(glGenBuffers, n, buffers);
}

void GL::generateMipmap(Enum target)
{
	g_OpenGLFunctions.glGenerateMipmap(target);
	CHECK_GL_ERROR1(glGenerateMipmap, target);
}

void GL::genFramebuffers(Sizei n, UInt * framebuffers)
{
	g_OpenGLFunctions.glGenFramebuffers(n, framebuffers);
	CHECK_GL_ERROR2(glGenFramebuffers, n, framebuffers);
}

void GL::genRenderbuffers(Sizei n, UInt * renderbuffers)
{
	g_OpenGLFunctions.glGenRenderbuffers(n, renderbuffers);
	CHECK_GL_ERROR2(glGenRenderbuffers, n, renderbuffers);
}

void GL::genTextures(Sizei n, UInt * textures)
{
	glGenTextures(n, textures);
	CHECK_GL_ERROR2(glGenTextures, n, textures);
}

void GL::getActiveAttrib(UInt prog, UInt idx, Sizei bufsz, Sizei * len, Int * sz, Enum * type, Char * name)
{
	GLenum tmp_type = 0;
	g_OpenGLFunctions.glGetActiveAttrib(prog, idx, bufsz, len, sz, &tmp_type, name);
	CHECK_GL_ERROR7(glGetActiveAttrib, prog, idx, bufsz, len, sz, type, name);
	*type = static_cast<Enum>(tmp_type);
}

void GL::getActiveUniform(UInt prog, UInt idx, Sizei bufsz, Sizei * len, Int * sz, Enum * type, Char * name)
{
	GLenum tmp_type = 0;
	g_OpenGLFunctions.glGetActiveUniform(prog, idx, bufsz, len, sz, &tmp_type, name);
	CHECK_GL_ERROR7(glGetActiveAttrib, prog, idx, bufsz, len, sz, type, name);
	*type = static_cast<Enum>(tmp_type);
}

void GL::getAttachedShaders(UInt program, Sizei maxcount, Sizei * count, UInt * shaders)
{
	g_OpenGLFunctions.glGetAttachedShaders(program, maxcount, count, shaders);
	CHECK_GL_ERROR4(glGetAttachedShaders, program, maxcount, count, shaders);
}

int GL::getAttribLocation(UInt program, const Char * name)
{
	int location = g_OpenGLFunctions.glGetAttribLocation(program, name);
	CHECK_GL_ERROR2(glGetAttribLocation, program, name);
	CHECK_GL_LOCATION(glGetAttribLocation, name, location)
	return location;
}

void GL::getBooleanv(Enum pname, Boolean * params)
{
	glGetBooleanv(pname, params);
	CHECK_GL_ERROR2(glGetBooleanv, pname, params);
}

void GL::getBufferParameteriv(Enum target, Enum pname, Int * params)
{
	g_OpenGLFunctions.glGetBufferParameteriv(target, pname, params);
	CHECK_GL_ERROR3(glGetBufferParameteriv, target, pname, params);
}

GL::Enum GL::getError()
{
	return static_cast<GL::Enum>(glGetError());
}

void GL::getFloatv(Enum pname, Float * params)
{
	glGetFloatv(pname, params);
	CHECK_GL_ERROR2(glGetFloatv, pname, params);
}

void GL::getFramebufferAttachmentParameteriv(Enum target, Enum attachment, Enum pname, Int * params)
{
	g_OpenGLFunctions.glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
	CHECK_GL_ERROR4(glGetFramebufferAttachmentParameteriv, target, attachment, pname, params);
}

void GL::getIntegerv(Enum pname, Int * params)
{
	glGetIntegerv(pname, params);
	CHECK_GL_ERROR2(glGetIntegerv, pname, params);
}

void GL::getProgramiv(UInt program, Enum pname, Int * params)
{
	g_OpenGLFunctions.glGetProgramiv(program, pname, params);
	CHECK_GL_ERROR3(glGetProgramiv, program, pname, params);
}

void GL::getProgramInfoLog(UInt program, Sizei bufsize, Sizei * length, Char * infolog)
{
	g_OpenGLFunctions.glGetProgramInfoLog(program, bufsize, length, infolog);
	CHECK_GL_ERROR4(glGetProgramInfoLog, program, bufsize, length, infolog);
}

void GL::getRenderbufferParameteriv(Enum target, Enum pname, Int * params)
{
	g_OpenGLFunctions.glGetRenderbufferParameteriv(target, pname, params);
	CHECK_GL_ERROR3(glGetRenderbufferParameteriv, target, pname, params);
}

void GL::getShaderiv(UInt shader, Enum pname, Int * params)
{
	g_OpenGLFunctions.glGetShaderiv(shader, pname, params);
	CHECK_GL_ERROR3(glGetShaderiv, shader, pname, params);
}

void GL::getShaderInfoLog(UInt shader, Sizei bufsize, Sizei * length, Char * infolog)
{
	g_OpenGLFunctions.glGetShaderInfoLog(shader, bufsize, length, infolog);
	CHECK_GL_ERROR4(glGetShaderInfoLog, shader, bufsize, length, infolog);
}

void GL::getShaderPrecisionFormat(Enum shadertype, Enum precisiontype, Int * range, Int * precision)
{
	g_OpenGLFunctions.glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
	CHECK_GL_ERROR4(glGetShaderPrecisionFormat, shadertype, precisiontype, range, precision);
}

void GL::getShaderSource(UInt shader, Sizei bufsize, Sizei * length, Char * source)
{
	g_OpenGLFunctions.glGetShaderSource(shader, bufsize, length, source);
	CHECK_GL_ERROR4(glGetShaderSource, shader, bufsize, length, source);
}

const GL::Char * GL::getString(Enum name)
{
	const Char * str = reinterpret_cast<const Char *>(glGetString(name));
	CHECK_GL_ERROR1(glGetString, name);
	return str;
}

void GL::getTexParameterfv(Enum target, Enum pname, Float * params)
{
	glGetTexParameterfv(target, pname, params);
	CHECK_GL_ERROR3(glGetTexParameterfv, target, pname, params);
}

void GL::getTexParameteriv(Enum target, Enum pname, Int * params)
{
	glGetTexParameteriv(target, pname, params);
	CHECK_GL_ERROR3(glGetTexParameteriv, target, pname, params);
}

void GL::getUniformfv(UInt program, Int location, Float * params)
{
	g_OpenGLFunctions.glGetUniformfv(program, location, params);
	CHECK_GL_ERROR3(glGetUniformfv, program, location, params);
}

void GL::getUniformiv(UInt program, Int location, Int * params)
{
	g_OpenGLFunctions.glGetUniformiv(program, location, params);
	CHECK_GL_ERROR3(glGetUniformiv, program, location, params);
}

int GL::getUniformLocation(UInt program, const Char * name)
{
	int location = g_OpenGLFunctions.glGetUniformLocation(program, name);
	CHECK_GL_ERROR2(glGetUniformLocation, program, name);
	CHECK_GL_LOCATION(glGetUniformLocation, name, location)
	return location;
}

void GL::getVertexAttribfv(UInt index, Enum pname, Float * params)
{
	g_OpenGLFunctions.glGetVertexAttribfv(index, pname, params);
	CHECK_GL_ERROR3(glGetVertexAttribfv, index, pname, params);
}

void GL::getVertexAttribiv(UInt index, Enum pname, Int * params)
{
	g_OpenGLFunctions.glGetVertexAttribiv(index, pname, params);
	CHECK_GL_ERROR3(glGetVertexAttribiv, index, pname, params);
}

void GL::getVertexAttribPointerv(UInt index, Enum pname, void ** pointer)
{
	g_OpenGLFunctions.glGetVertexAttribPointerv(index, pname, pointer);
	CHECK_GL_ERROR3(glGetVertexAttribPointerv, index, pname, pointer);
}

void GL::hint(Enum target, Enum mode)
{
	glHint(target, mode);
	CHECK_GL_ERROR2(glHint, target, mode);
}

GL::Boolean GL::isBuffer(UInt buffer)
{
	Boolean flag = g_OpenGLFunctions.glIsBuffer(buffer);
	CHECK_GL_ERROR1(glIsBuffer, buffer);
	return flag;
}

GL::Boolean GL::isEnabled(Enum cap)
{
	Boolean flag = glIsEnabled(cap);
	CHECK_GL_ERROR1(glIsEnabled, cap);
	return flag;
}

GL::Boolean GL::isFramebuffer(UInt framebuffer)
{
	Boolean flag = g_OpenGLFunctions.glIsFramebuffer(framebuffer);
	CHECK_GL_ERROR1(glIsFramebuffer, framebuffer);
	return flag;
}

GL::Boolean GL::isProgram(UInt program)
{
	Boolean flag = g_OpenGLFunctions.glIsProgram(program);
	CHECK_GL_ERROR1(glIsProgram, program);
	return flag;
}

GL::Boolean GL::isRenderbuffer(UInt renderbuffer)
{
	Boolean flag = g_OpenGLFunctions.glIsRenderbuffer(renderbuffer);
	CHECK_GL_ERROR1(glIsRenderbuffer, renderbuffer);
	return flag;
}

GL::Boolean GL::isShader(UInt shader)
{
	Boolean flag = g_OpenGLFunctions.glIsShader(shader);
	CHECK_GL_ERROR1(glIsShader, shader);
	return flag;
}

GL::Boolean GL::isTexture(UInt texture)
{
	Boolean flag = glIsTexture(texture);
	CHECK_GL_ERROR1(glIsTexture, texture);
	return flag;
}

void GL::lineWidth(Float width)
{
	glLineWidth(width);
	CHECK_GL_ERROR1(glLineWidth, width);
}

void GL::linkProgram(UInt program)
{
	g_OpenGLFunctions.glLinkProgram(program);
	CHECK_GL_ERROR1(glLinkProgram, program);
}

void GL::pixelStorei(Enum pname, Int param)
{
	glPixelStorei(pname, param);
	CHECK_GL_ERROR2(glPixelStorei, pname, param);
}

void GL::polygonOffset(Float factor, Float units)
{
	glPolygonOffset(factor, units);
	CHECK_GL_ERROR2(glPolygonOffset, factor, units);
}

void GL::readPixels(Int x, Int y, Sizei width, Sizei height, Enum format, Enum type, void * pixels)
{
	glReadPixels(x, y, width, height, format, type, pixels);
	CHECK_GL_ERROR7(glReadPixels, x, y, width, height, format, type, pixels);
}

void GL::releaseShaderCompiler()
{
	g_OpenGLFunctions.glReleaseShaderCompiler();
	CHECK_GL_ERROR0(glReleaseShaderCompiler);
}

void GL::renderbufferStorage(Enum target, Enum internalformat, Sizei width, Sizei height)
{
	g_OpenGLFunctions.glRenderbufferStorage(target, internalformat, width, height);
	CHECK_GL_ERROR4(glRenderbufferStorage, target, internalformat, width, height);
}

void GL::sampleCoverage(Clampf value, Boolean invert)
{
	g_OpenGLFunctions.glSampleCoverage(value, invert);
	CHECK_GL_ERROR2(glSampleCoverage, value, invert);
}

void GL::scissor(Int x, Int y, Sizei width, Sizei height)
{
	glScissor(x, y, width, height);
	CHECK_GL_ERROR4(glScissor, x, y, width, height);
}

void GL::shaderBinary(Sizei n, const UInt * shaders, Enum binaryformat, const void * binary, Sizei length)
{
	g_OpenGLFunctions.glShaderBinary(n, shaders, binaryformat, binary, length);
	CHECK_GL_ERROR5(glShaderBinary, n, shaders, binaryformat, binary, length);
}

void GL::shaderSource(UInt shader, Sizei count, const Char ** string, const Int * length)
{
	g_OpenGLFunctions.glShaderSource(shader, count, string, length);
	CHECK_GL_ERROR4(glShaderSource, shader, count, string, length);
}

void GL::stencilFunc(Enum func, Int ref, UInt mask)
{
	glStencilFunc(func, ref, mask);
	CHECK_GL_ERROR3(glStencilFunc, func, ref, mask);
}

void GL::stencilFuncSeparate(Enum face, Enum func, Int ref, UInt mask)
{
	g_OpenGLFunctions.glStencilFuncSeparate(face, func, ref, mask);
	CHECK_GL_ERROR4(glStencilFuncSeparate, face, func, ref, mask);
}

void GL::stencilMask(UInt mask)
{
	glStencilMask(mask);
	CHECK_GL_ERROR1(glStencilMask, mask);
}

void GL::stencilMaskSeparate(Enum face, UInt mask)
{
	g_OpenGLFunctions.glStencilMaskSeparate(face, mask);
	CHECK_GL_ERROR2(glStencilMaskSeparate, face, mask);
}

void GL::stencilOp(Enum fail, Enum zfail, Enum zpass)
{
	glStencilOp(fail, zfail, zpass);
	CHECK_GL_ERROR3(glStencilOp, fail, zfail, zpass);
}

void GL::stencilOpSeparate(Enum face, Enum fail, Enum zfail, Enum zpass)
{
	g_OpenGLFunctions.glStencilOpSeparate(face, fail, zfail, zpass);
	CHECK_GL_ERROR4(glStencilOpSeparate, face, fail, zfail, zpass);
}

void GL::texImage2D(Enum target, Int level, Int internalformat, Sizei width, Sizei height, Int border,
	Enum format, Enum type, const void * pixels)
{
	glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
	CHECK_GL_ERROR9(glTexImage2D, target, level, internalformat, width, height, border, format, type, pixels);
}

void GL::texParameterf(Enum target, Enum pname, Float param)
{
	glTexParameterf(target, pname, param);
	CHECK_GL_ERROR3(glTexParameterf, target, pname, param);
}

void GL::texParameterfv(Enum target, Enum pname, const Float * params)
{
	glTexParameterfv(target, pname, params);
	CHECK_GL_ERROR3(glTexParameterfv, target, pname, params);
}

void GL::texParameteri(Enum target, Enum pname, Int param)
{
	glTexParameteri(target, pname, param);
	CHECK_GL_ERROR3(glTexParameteri, target, pname, param);
}

void GL::texParameteriv(Enum target, Enum pname, const Int * params)
{
	glTexParameteriv(target, pname, params);
	CHECK_GL_ERROR3(glTexParameteriv, target, pname, params);
}

void GL::texSubImage2D(Enum target, Int level, Int xoffset, Int yoffset, Sizei width, Sizei height,
		Enum format, Enum type, const void * pixels)
{
	glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
	CHECK_GL_ERROR9(glTexSubImage2D, target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void GL::uniform1f(Int location, Float x)
{
	g_OpenGLFunctions.glUniform1f(location, x);
	CHECK_GL_ERROR2(glUniform1f, location, x);
}

void GL::uniform1fv(Int location, Sizei count, const Float * v)
{
	g_OpenGLFunctions.glUniform1fv(location, count, v);
	CHECK_GL_ERROR3(glUniform1fv, location, count, v);
}

void GL::uniform1i(Int location, Int x)
{
	g_OpenGLFunctions.glUniform1i(location, x);
	CHECK_GL_ERROR2(glUniform1i, location, x);
}

void GL::uniform1iv(Int location, Sizei count, const Int * v)
{
	g_OpenGLFunctions.glUniform1iv(location, count, v);
	CHECK_GL_ERROR3(glUniform1iv, location, count, v);
}

void GL::uniform2f(Int location, Float x, Float y)
{
	g_OpenGLFunctions.glUniform2f(location, x, y);
	CHECK_GL_ERROR3(glUniform2f, location, x, y);
}

void GL::uniform2fv(Int location, Sizei count, const Float * v)
{
	g_OpenGLFunctions.glUniform2fv(location, count, v);
	CHECK_GL_ERROR3(glUniform2fv, location, count, v);
}

void GL::uniform2i(Int location, Int x, Int y)
{
	g_OpenGLFunctions.glUniform2i(location, x, y);
	CHECK_GL_ERROR3(glUniform2i, location, x, y);
}

void GL::uniform2iv(Int location, Sizei count, const Int * v)
{
	g_OpenGLFunctions.glUniform2iv(location, count, v);
	CHECK_GL_ERROR3(glUniform2iv, location, count, v);
}

void GL::uniform3f(Int location, Float x, Float y, Float z)
{
	g_OpenGLFunctions.glUniform3f(location, x, y, z);
	CHECK_GL_ERROR4(glUniform3f, location, x, y, z);
}

void GL::uniform3fv(Int location, Sizei count, const Float * v)
{
	g_OpenGLFunctions.glUniform3fv(location, count, v);
	CHECK_GL_ERROR3(glUniform3fv, location, count, v);
}

void GL::uniform3i(Int location, Int x, Int y, Int z)
{
	g_OpenGLFunctions.glUniform3i(location, x, y, z);
	CHECK_GL_ERROR4(glUniform3i, location, x, y, z);
}

void GL::uniform3iv(Int location, Sizei count, const Int * v)
{
	g_OpenGLFunctions.glUniform3iv(location, count, v);
	CHECK_GL_ERROR3(glUniform3iv, location, count, v);
}

void GL::uniform4f(Int location, Float x, Float y, Float z, Float w)
{
	g_OpenGLFunctions.glUniform4f(location, x, y, z, w);
	CHECK_GL_ERROR5(glUniform4f, location, x, y, z, w);
}

void GL::uniform4fv(Int location, Sizei count, const Float * v)
{
	g_OpenGLFunctions.glUniform4fv(location, count, v);
	CHECK_GL_ERROR3(glUniform4fv, location, count, v);
}

void GL::uniform4i(Int location, Int x, Int y, Int z, Int w)
{
	g_OpenGLFunctions.glUniform4i(location, x, y, z, w);
	CHECK_GL_ERROR5(glUniform4i, location, x, y, z, w);
}

void GL::uniform4iv(Int location, Sizei count, const Int * v)
{
	g_OpenGLFunctions.glUniform4iv(location, count, v);
	CHECK_GL_ERROR3(glUniform4iv, location, count, v);
}

void GL::uniformMatrix2fv(Int location, Sizei count, Boolean transpose, const Float * value)
{
	g_OpenGLFunctions.glUniformMatrix2fv(location, count, transpose, value);
	CHECK_GL_ERROR4(glUniformMatrix2fv, location, count, transpose, value);
}

void GL::uniformMatrix3fv(Int location, Sizei count, Boolean transpose, const Float * value)
{
	g_OpenGLFunctions.glUniformMatrix3fv(location, count, transpose, value);
	CHECK_GL_ERROR4(glUniformMatrix3fv, location, count, transpose, value);
}

void GL::uniformMatrix4fv(Int location, Sizei count, Boolean transpose, const Float * value)
{
	g_OpenGLFunctions.glUniformMatrix4fv(location, count, transpose, value);
	CHECK_GL_ERROR4(glUniformMatrix4fv, location, count, transpose, value);
}

void GL::useProgram(UInt program)
{
	g_OpenGLFunctions.glUseProgram(program);
	CHECK_GL_ERROR1(glUseProgram, program);
}

void GL::validateProgram(UInt program)
{
	g_OpenGLFunctions.glValidateProgram(program);
	CHECK_GL_ERROR1(glValidateProgram, program);
}

void GL::vertexAttrib1f(UInt indx, Float x)
{
	g_OpenGLFunctions.glVertexAttrib1f(indx, x);
	CHECK_GL_ERROR2(glVertexAttrib1f, indx, x);
}

void GL::vertexAttrib1fv(UInt indx, const Float * values)
{
	g_OpenGLFunctions.glVertexAttrib1fv(indx, values);
	CHECK_GL_ERROR2(glVertexAttrib1fv, indx, values);
}

void GL::vertexAttrib2f(UInt indx, Float x, Float y)
{
	g_OpenGLFunctions.glVertexAttrib2f(indx, x, y);
	CHECK_GL_ERROR3(glVertexAttrib2f, indx, x, y);
}

void GL::vertexAttrib2fv(UInt indx, const Float * values)
{
	g_OpenGLFunctions.glVertexAttrib2fv(indx, values);
	CHECK_GL_ERROR2(glVertexAttrib2fv, indx, values);
}

void GL::vertexAttrib3f(UInt indx, Float x, Float y, Float z)
{
	g_OpenGLFunctions.glVertexAttrib3f(indx, x, y, z);
	CHECK_GL_ERROR4(glVertexAttrib3f, indx, x, y, z);
}

void GL::vertexAttrib3fv(UInt indx, const Float * values)
{
	g_OpenGLFunctions.glVertexAttrib3fv(indx, values);
	CHECK_GL_ERROR2(glVertexAttrib3fv, indx, values);
}

void GL::vertexAttrib4f(UInt indx, Float x, Float y, Float z, Float w)
{
	g_OpenGLFunctions.glVertexAttrib4f(indx, x, y, z, w);
	CHECK_GL_ERROR5(glVertexAttrib4f, indx, x, y, z, w);
}

void GL::vertexAttrib4fv(UInt indx, const Float * values)
{
	g_OpenGLFunctions.glVertexAttrib4fv(indx, values);
	CHECK_GL_ERROR2(glVertexAttrib4fv, indx, values);
}

void GL::vertexAttribPointer(UInt indx, Int size, Enum type, Boolean norm, Sizei stride, const void * ptr)
{
	g_OpenGLFunctions.glVertexAttribPointer(indx, size, type, norm, stride, ptr);
	CHECK_GL_ERROR6(glVertexAttribPointer, indx, size, type, norm, stride, ptr);
}

void GL::viewport(Int x, Int y, Sizei width, Sizei height)
{
	glViewport(x, y, width, height);
	CHECK_GL_ERROR4(glViewport, x, y, width, height);
}
