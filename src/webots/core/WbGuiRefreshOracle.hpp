// Copyright 1996-2020 Cyberbotics Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef WB_GUI_REFRESH_ORACLE_HPP
#define WB_GUI_REFRESH_ORACLE_HPP

//
// Description: Helper class to know when critical
//              GUI part have to be refreshed
//

#include <QtCore/QObject>
#include <QtCore/QTime>
#include <QtCore/QTimer>

class WbGuiRefreshOracle : public QObject {
  Q_OBJECT

public:
  static WbGuiRefreshOracle *instance();

  bool canRefreshNow() const { return mCanRefreshNow; }
  int elapsed() const { return mLastRefreshTime.elapsed(); }

signals:
  void canRefreshActivated();
  void canRefreshUpdated();

private:
  static void cleanup();

  WbGuiRefreshOracle();
  ~WbGuiRefreshOracle();

  static WbGuiRefreshOracle *cInstance;

  bool mCanRefreshNow;
  QTime mLastRefreshTime;
  QTimer mGlobalRefreshTimer;

private slots:
  void updateFlags();
};

#endif
