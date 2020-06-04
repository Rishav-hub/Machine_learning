/**
 * Copyright (C) 2016 Turi
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license. See the LICENSE file for details.
 */
#ifndef GRAPHLAB_UNITY_AUTO_CLOSE_SARRAY
#define GRAPHLAB_UNITY_AUTO_CLOSE_SARRAY

namespace graphlab {
/**
* helper class to auto open SArray for write in constructor and and then close
* the sarray as it is out of scope
**/
class auto_close_sarrays {
public:
  auto_close_sarrays(std::vector<flex_type_enum> column_types) {
    m_columns.resize(column_types.size());
    for (size_t col_idx  = 0; col_idx < column_types.size(); col_idx++) {
      m_columns[col_idx] = std::make_shared<sarray<flexible_type>>();
      m_columns[col_idx]->open_for_write();
      m_columns[col_idx]->set_type(column_types[col_idx]);
    }
  }

  ~auto_close_sarrays() {
    close();
  }

  void close() {
    if (!m_closed) {
      for(auto column: m_columns) {
        column->close();
      }
      m_closed = true;
    }
  }

  std::vector<std::shared_ptr<sarray<flexible_type>>> get_sarrays() {
    return m_columns;
  }

private:
  std::vector<std::shared_ptr<sarray<flexible_type>>> m_columns;
  bool m_closed = false;
};

}
#endif
