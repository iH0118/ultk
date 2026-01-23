# UIB - The UIDL Bytecode Format

- all numbers use little endian format
- bools are encoded as individual bytes
- all sizes are in bytes

file structure:
```
"UIB" header
<application>
```

application:
```
<uint32> application_size
<uint16> meta_name_size
<string> meta_name
<uint16> meta_version_size
<string> meta_version
<uint16> meta_id_size
<string> meta_id
<uint16> meta_creator_size
<string> meta_creator
<uint16> meta_copyright_size
<string> meta_copyright
<uint16> meta_url_size
<string> meta_url
<uint16> num_canvas
<canvas>
(<canvas> ...)
```

canvas: 
```
<uint32> canvas_size
<enum8> canvas_type
<uint16> id_size
<string> id
<uint16> title_size
<string> title
<uint16> size_x
<uint16> size_y
<widget>
```

widget:
```
<uint32> widget_size
<enum8> widget_type
<widget_data>
```

widget_data:
- void:
  ```
  ```

- array_static:
  ```
  <uint16> id_size
  <string> id
  <uint8> num_rows
  <uint8> num_cols
  <enum8> alignment
  <bool> scrollable_x
  <bool> scrollable_y
  <uint16> num_children
  <widget>
  (<widget> ...)
  ```

- array_dynamic:
  ```
  <uint16> id_size
  <string> id
  <enum8> alignment
  <bool> keep_grid
  <enum8> reflow_direction
  <uint8> max_reflow_sections
  <uint16> num_children
  <widget>
  (<widget> ...)
  ```

- button:
  ```
  <uint16> id_size
  <string> id
  <uint16> label_size
  <string> label
  <enum8> label_align_x
  <enum8> label_align_y
  <uint16> size_min_x
  <uint16> size_min_y
  <uint16> size_max_x
  <uint16> size_max_y
  <uint16> callback_id_press_size
  <string> callback_id_press
  ```

- checkbox:
  ```
  <uint16> id_size
  <string> id
  <uint16> label_size
  <string> label
  <bool> checked
  <uint16> callback_id_check_size
  <string> callback_id_check
  <uint16> callback_id_uncheck_size
  <string> callback_id_uncheck
  ```

- container:
  ```
  <uint16> id_size
  <string> id
  <fp32> pad_relative_l
  <fp32> pad_relative_r
  <fp32> pad_relative_t
  <fp32> pad_relative_b
  <uint16> pad_absolute_l
  <uint16> pad_absolute_r
  <uint16> pad_absolute_t
  <uint16> pad_absolute_b
  <widget>
  ```

- container_label:
  ```
  <uint16> id_size
  <string> id
  <uint16> label_size
  <string> label
  <enum8> label_align
  <bool> border
  <widget>
  ```