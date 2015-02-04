#pragma once

namespace SOUI
{
    class SScrollText : public SStatic
    {
        SOUI_CLASS_NAME(SScrollText,L"scrolltext")
    public:
        SScrollText(void);
        ~SScrollText(void);
        
        void SetWindowText(const SStringT & strText);
    protected:
        void OnTimer(char cTimer);
        void OnPaint(IRenderTarget *pRT);
        void OnSize(UINT nType, CSize size);
        void OnShowWindow(BOOL bShow, UINT nStatus);
        
        void UpdateScrollInfo(CSize size);
        
        SOUI_MSG_MAP_BEGIN()
            MSG_WM_PAINT_EX(OnPaint)
            MSG_WM_TIMER_EX(OnTimer)
            MSG_WM_SIZE(OnSize)
            MSG_WM_SHOWWINDOW(OnShowWindow)
        SOUI_MSG_MAP_END()
        
        SOUI_ATTRS_BEGIN()
            ATTR_INT(L"speed",m_nSpeed,FALSE)
        SOUI_ATTRS_END()
        
        int m_nSpeed;
        int m_nOffset;
        int m_nScrollWidth;
    };

}
