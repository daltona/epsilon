#ifndef APPS_CURSOR_VIEW_H
#define APPS_CURSOR_VIEW_H

#include <escher.h>

class CursorView : public View {
public:
  using View::View;
  void drawRect(KDContext * ctx, KDRect rect) const override;
};

#endif