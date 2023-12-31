﻿#include <Siv3D.hpp> // OpenSiv3D v0.6.11

#include <Magnolia/Core/Object.hpp>

void Main()
{

	auto package = magnolia::Reference::FindReference(UTEXT("Object"));
	if (package.typeIndex == typeid(magnolia::Object))
	{
		Print << UTEXT("package == object");
	}

	while (System::Update())
	{
		
	}
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//
