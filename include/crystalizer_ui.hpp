/*
 *  Copyright © 2017-2020 Wellington Wallace
 *
 *  This file is part of PulseEffects.
 *
 *  PulseEffects is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  PulseEffects is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with PulseEffects.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef CRYSTALIZER_UI_HPP
#define CRYSTALIZER_UI_HPP

#include "plugin_ui_base.hpp"

class CrystalizerUi : public Gtk::Box, public PluginUiBase {
 public:
  CrystalizerUi(BaseObjectType* cobject,
                const Glib::RefPtr<Gtk::Builder>& builder,
                const std::string& schema,
                const std::string& schema_path);
  CrystalizerUi(const CrystalizerUi&) = delete;
  auto operator=(const CrystalizerUi&) -> CrystalizerUi& = delete;
  CrystalizerUi(const CrystalizerUi&&) = delete;
  auto operator=(const CrystalizerUi&&) -> CrystalizerUi& = delete;
  ~CrystalizerUi() override;

  void on_new_range_before(double value);

  void on_new_range_after(double value);

  void reset() override;

 private:
  Gtk::Grid* bands_grid = nullptr;

  Gtk::LevelBar *range_before = nullptr, *range_after = nullptr;
  Gtk::Label *range_before_label = nullptr, *range_after_label = nullptr;
  Gtk::ToggleButton* aggressive = nullptr;

  Glib::RefPtr<Gtk::Adjustment> input_gain, output_gain;

  void build_bands(const int& nbands);
};

#endif
