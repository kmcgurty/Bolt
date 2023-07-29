#ifndef _BOLT_WINDOW_LAUNCHER_HXX_
#define _BOLT_WINDOW_LAUNCHER_HXX_

#include "../browser.hxx"

#include <filesystem>

namespace Browser {
	struct Launcher: public Window {
		Launcher(CefRefPtr<CefClient>, Details, bool, const std::map<std::string, InternalFile>* const, std::filesystem::path);

		CefRefPtr<CefResourceRequestHandler> GetResourceRequestHandler(
			CefRefPtr<CefBrowser>,
			CefRefPtr<CefFrame>,
			CefRefPtr<CefRequest>,
			bool,
			bool,
			const CefString&,
			bool&
		) override;

		private:
			std::string internal_url = "https://bolt-internal/";
			const std::map<std::string, InternalFile>* internal_pages;
			std::filesystem::path data_dir;
			std::filesystem::path creds_path;
			std::filesystem::path rs3_path;
			std::filesystem::path rs3_hash_path;
	};
}

#endif