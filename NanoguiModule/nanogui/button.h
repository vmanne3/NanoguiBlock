/*
    nanogui/button.h -- [Normal/Toggle/Radio/Popup] Button widget

    NanoGUI was developed by Wenzel Jakob <wenzel@inf.ethz.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#pragma once

NAMESPACE_BEGIN (nanogui)

class  Button : public Widget
{
   public:
      /// Flags to specify the button behavior (can be combined with binary OR)
      enum Flags
      {
         NormalButton = 1,
         RadioButton  = 2,
         ToggleButton = 4,
         PopupButton  = 8
      };

      enum class IconPosition
      {
         Left,
         LeftCentered,
         RightCentered,
         Right
      };

      Button (Widget * parent, const std::string & caption = "Untitled", int icon = 0);

      const std::string & caption() const
      {
         return mCaption;
      }
      void setCaption (const std::string & caption)
      {
         mCaption = caption;
      }

      const Colour & backgroundColor() const
      {
         return mBackgroundColor;
      }
      void setBackgroundColor (const Colour & backgroundColor)
      {
         mBackgroundColor = backgroundColor;
      }

      const Colour & textColor() const
      {
         return mTextColor;
      }
      void setTextColor (const Colour & textColor)
      {
         mTextColor = textColor;
      }

      int icon() const
      {
         return mIcon;
      }
      void setIcon (int icon)
      {
         mIcon = icon;
      }

      int flags() const
      {
         return mFlags;
      }
      void setFlags (int buttonFlags)
      {
         mFlags = buttonFlags;
      }

      IconPosition iconPosition() const
      {
         return mIconPosition;
      }
      void setIconPosition (IconPosition iconPosition)
      {
         mIconPosition = iconPosition;
      }

      bool pushed() const
      {
         return mPushed;
      }
      void setPushed (bool pushed)
      {
         mPushed = pushed;
      }

      /// Set the push callback (for any type of button)
      std::function<void()> callback() const
      {
         return mCallback;
      }
      void setCallback (const std::function<void()> & callback)
      {
         mCallback = callback;
      }

      /// Set the change callback (for toggle buttons)
      std::function<void (bool)> changeCallback() const
      {
         return mChangeCallback;
      }
      void setChangeCallback (const std::function<void (bool)> & callback)
      {
         mChangeCallback = callback;
      }

      /// Set the button group (for radio buttons)
      void setButtonGroup (const std::vector<Button *> & buttonGroup)
      {
         mButtonGroup = buttonGroup;
      }
      const std::vector<Button *> & buttonGroup() const
      {
         return mButtonGroup;
      }

      virtual ivec2 preferredSize (NVGcontext * ctx) const;
      virtual bool mouseButtonEvent (const ivec2 & p, int button, bool down, int modifiers);
      virtual void draw (NVGcontext * ctx);
   protected:
      std::string mCaption;
      int mIcon;
      IconPosition mIconPosition;
      bool mPushed;
      int mFlags;
      Colour mBackgroundColor;
      Colour mTextColor;
      std::function<void()> mCallback;
      std::function<void (bool)> mChangeCallback;
      std::vector<Button *> mButtonGroup;
};

NAMESPACE_END (nanogui)
