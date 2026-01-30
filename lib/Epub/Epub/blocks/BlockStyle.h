#pragma once

#include <cstdint>

/**
 * BlockStyle - Block-level CSS properties for paragraphs
 *
 * Used to track margin/padding spacing and text indentation for block elements.
 * Padding is treated similarly to margins for rendering purposes.
 */
struct BlockStyle {
  int16_t marginTop = 0;           // pixels
  int16_t marginBottom = 0;        // pixels
  int16_t marginLeft = 0;          // pixels
  int16_t marginRight = 0;         // pixels
  int16_t paddingTop = 0;          // pixels (treated same as margin)
  int16_t paddingBottom = 0;       // pixels (treated same as margin)
  int16_t paddingLeft = 0;         // pixels (treated same as margin)
  int16_t paddingRight = 0;        // pixels (treated same as margin)
  int16_t textIndent = 0;          // pixels
  bool textIndentDefined = false;  // true if text-indent was explicitly set in CSS

  // Combined horizontal insets (margin + padding)
  [[nodiscard]] int16_t leftInset() const { return marginLeft + paddingLeft; }
  [[nodiscard]] int16_t rightInset() const { return marginRight + paddingRight; }
  [[nodiscard]] int16_t totalHorizontalInset() const { return leftInset() + rightInset(); }
};
