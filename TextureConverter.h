#pragma once
#include <string>
#include <DirectXTex.h>

class TextureConverter
{
public:
	/// <summary>
	/// テクスチャをWICからDDSに変換する
	/// </summary>
	/// <param name = "fliePath">ファイルパス</param>
	void ConverterTextureWICToDDS(const std::string& filePath);

	/// <summary>
	/// パスとファイル名を分離する
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void SeparateFilePath(const std::wstring& filePath);

	
	/// <summary>
	/// テクスチャファイル読み込み
	/// </summary>
	/// <param name = "fliePath">ファイルパス</param>
	void LoadWICTextureFromFile(const std::string& filePath);

	static std::wstring ConvertMultiByteStringToWideString(const std::string& String);

private:
	/// <summary>
	/// DDSテクスチャとしてファイル書き出し
	/// </summary>
	void SaveDDSTextureToFile();


private:
	//画像の情報
	DirectX::TexMetadata metadata_;
	//画像のイメージのコンテナ
	DirectX::ScratchImage scratchImage_;

	//ディレクトリパス
	std::wstring directoryPath_;
	//ファイル名
	std::wstring fileName_;
	//ファイル拡張子
	std::wstring fileExt_;
};

