#ifndef MAXIMIZER_HPP
#define MAXIMIZER_HPP

#include <sigc++/sigc++.h>
#include <array>
#include "plugin_base.hpp"

class Maximizer : public PluginBase {
 public:
  Maximizer(const std::string& tag, const std::string& schema);
  Maximizer(const Maximizer&) = delete;
  auto operator=(const Maximizer&) -> Maximizer& = delete;
  Maximizer(const Maximizer&&) = delete;
  auto operator=(const Maximizer &&) -> Maximizer& = delete;
  ~Maximizer() override;

  GstElement* maximizer = nullptr;

  sigc::connection reduction_connection;

  sigc::signal<void, double> reduction;

 private:
  void bind_to_gsettings();
};

#endif
