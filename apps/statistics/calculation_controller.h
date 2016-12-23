#ifndef STATISTICS_CALCULATION_CONTROLLER_H
#define STATISTICS_CALCULATION_CONTROLLER_H

#include <escher.h>
#include "data.h"

namespace Statistics {

class CalculationController : public ViewController, public AlternateEmptyViewDelegate, public TableViewDataSource {

public:
  CalculationController(Responder * parentResponder, Data * data);
  const char * title() const override;
  View * view() override;
  bool handleEvent(Ion::Events::Event event) override;
  void didBecomeFirstResponder() override;

  bool isEmpty() override;
  const char * emptyMessage() override;
  Responder * defaultController() override;

  int numberOfRows() override;
  int numberOfColumns() override;
  void willDisplayCellAtLocation(TableViewCell * cell, int i, int j) override;
  KDCoordinate columnWidth(int i) override;
  KDCoordinate rowHeight(int j) override;
  KDCoordinate cumulatedWidthFromIndex(int i) override;
  KDCoordinate cumulatedHeightFromIndex(int j) override;
  int indexFromCumulatedWidth(KDCoordinate offsetX) override;
  int indexFromCumulatedHeight(KDCoordinate offsetY) override;
  TableViewCell * reusableCell(int index, int type) override;
  int reusableCellCount(int type) override;
  int typeAtLocation(int i, int j) override;
private:
  Responder * tabController() const;
  constexpr static int k_totalNumberOfRows = 13;
  constexpr static int k_maxNumberOfDisplayableRows = 10;
  static constexpr KDCoordinate k_cellHeight = 25;
  static constexpr KDCoordinate k_cellWidth = 320/2 - Metric::RightMargin;
  EvenOddPointerTextCell m_titleCells[k_maxNumberOfDisplayableRows];
  EvenOddBufferTextCell m_calculationCells[k_maxNumberOfDisplayableRows];
  SelectableTableView m_selectableTableView;
  Data * m_data;
};

}


#endif