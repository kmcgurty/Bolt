#ifndef _BOLT_BROWSER_VIEW_DELEGATE_HXX_
#define _BOLT_BROWSER_VIEW_DELEGATE_HXX_

#include "include/views/cef_browser_view_delegate.h"
#include "details.hxx"

namespace Browser {
	/// Implementation of CefBrowserViewDelegate. Create on the heap as CefRefPtr.
	/// https://github.com/chromiumembedded/cef/blob/5563/include/cef_browser_view_delegate.h
	struct BrowserViewDelegate: public CefBrowserViewDelegate {
		const Details details;

		BrowserViewDelegate(Details);
		CefSize GetPreferredSize(CefRefPtr<CefView>) override;
		CefSize GetMinimumSize(CefRefPtr<CefView>) override;
		CefSize GetMaximumSize(CefRefPtr<CefView>) override;
		cef_chrome_toolbar_type_t GetChromeToolbarType() override;

		private:
			IMPLEMENT_REFCOUNTING(BrowserViewDelegate);
			DISALLOW_COPY_AND_ASSIGN(BrowserViewDelegate);
	};
}

#endif