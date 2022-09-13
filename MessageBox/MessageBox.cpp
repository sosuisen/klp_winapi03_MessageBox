#include <windows.h>
#include <string>

int APIENTRY wWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	MSGBOXPARAMS mbp;

	// 構造体をゼロクリア
	ZeroMemory(&mbp, sizeof mbp);

	// 構造体に属性を設定
	mbp.cbSize = sizeof mbp;
	mbp.hInstance = hInstance;
	mbp.lpszCaption = L"課題";
	mbp.lpszText = lpCmdLine;
	// 発展課題
	// 解法１
	std::wstring label = L"引数は「" + std::wstring(lpCmdLine) + L"」";
	mbp.lpszText = label.c_str();

	/*
	// 解法２　sprintf系関数を使う。
	// Unicode は文字数の予想が難しいのでおすすめしない。
	wchar_t format[] = L"引数は「%s」";
	// フォーマット後文字列のバッファのサイズ（文字数）を求める
	// wcslen はワイド文字（２バイト）単位で文字数を数える
	// %s の分（2文字）減らして、終端の null文字分を加える
	size_t size = wcslen(format) + wcslen(lpCmdLine) - 2 + 1;
	wchar_t* buf = new wchar_t[size];
	// ワイド文字対応(w)の sprintf で
	// セキュリティの強化された(_s)関数 swprintf_s を使う
	swprintf_s(buf, size, format, lpCmdLine);
	mbp.lpszText = buf;
	*/

	mbp.dwStyle = MB_OK | MB_ICONASTERISK;
	mbp.dwStyle = MB_CANCELTRYCONTINUE | MB_ICONQUESTION;

	// メッセージボックスを表示
	MessageBoxIndirect(&mbp);
	// メッセージボックスを再表示
	// MessageBoxIndirect(&mbp);
	return 0;
}