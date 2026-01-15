# UIDL - The ULTK User Interface Definition Language

## Syntax
types of objects:
- Scalars
  ```
  bool: true
  int: 42
  float: 3.14
  string: "meow"
  ```

- Enums
  ```
  type: button
  alignment: center
  ```

- Lists
  ```
  list: {
    item1: <object>,
    item2: <object>,
    ...
  }
  ```
- Arrays
  ```
  array: [
    <object>,
    <object>,
    ...
  ]
  ```

Comments
```
# i am a comment
```

## File structure

```
application: {
  metadata: {
    name: <string>,
    version: <string>,
    id: <string>,
    creator: <string>,
    copyright: <string>,
    url: <string>
  },
  canvas: [
    <canvas>,
    <canvas>,
    ...
  ]
}
```

### Canvas struct
  ```
  <canvas>: <canvas_type> {
    id: <string>,
    title: <string>,
    size_x: <int>, # 0 for dynamic calculation
    size_y: <int>, # 0 for dynamic calculation
    w_top: <widget>
  }
  ```
  ```
  <canvas_type>: (application | utility | popup | tooltip)
  ```

## Widgets

- Void
  ```
  <widget>: void
  ```

- Static array
  ```
  <widget>: array_static {
    id: <string>,
    num_rows: <int>,
    num_cols: <int>,
    alignment: (left | right | center | fill),
    scrollable_x: <bool>,
    scrollable_y: <bool>,
    w_children: [
      <widget>,
      ...
    ] # num_children = num_rows * num_cols
  }
  ```

- Dynamic array
  ```
  <widget>: array_dynamic {
    id: <string>,
    num_children: <int>,
    alignment: (left | right | center | fill),
    keep_grid: <bool>,
    reflow_direction: (horizontal | vertical),
    max_reflow_sections: <int> # 0 for no limit
    w_children: [
      <widget>,
      ...
    ]
  }
  ```

- Button
  ```
  <widget>: button {
    id: <string>,
    label: <string>,
    label_align_x: (left | center | right),
    label_align_y: (top | center | bottom),
    size_min_x: <int>, # 0 for no limit
    size_min_y: <int>, # 0 for no limit
    size_max_x: <int>, # 0 for no limit
    size_max_y: <int>, # 0 for no limit
    callback_id: <string>
  }
  ```

- Checkbox
  ```
  <widget>: checkbox {
    id: <string>,
    label: <string>,
    checked: <bool>,
    callback_id: <string>
  }
  ```

- Container
  ```
  <widget>: container {
    id: <string>,
    padding_relative: {
      l: <float>,
      r: <float>,
      t: <float>,
      b: <float>
    },
    padding_absolute: {
      l: <int>,
      r: <int>,
      t: <int>,
      b: <int>
    },
    w_child: <widget>
  }
  ```

- Labeled container
  ```
  <widget>: container_label {
    id: <string>,
    label: <string>,
    label_align: (left | center | right),
    border <bool>,
    w_child: <widget>
  }
  ```

> TODO: finish writing this i guess

## UIB bytecode format

- all numbers use little endian format
- all sizes are in bytes

file structure:
```
"UIB" header
<uint32> application_size
<application>
```

application:
```
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
<uint16> canvas_count
<uint32> canvas_size
<canvas>
(<uint32> canvas_size
 <canvas>
 ...)
```

canvas: 
```
<uint8> canvas_type
<uint16> id_size
<string> id
<uint16> title_size
<string> title
<uint16> size_x
<uint16> size_y
<uint32> widget_size
<widget>
```

widget:
```
<uint8> widget_type
<uint16> id_size
<string> id
<widget_data>
```

widget_data:
- array_static
  ```
  <uint8> num_rows
  <uint8> num_cols
  <uint8> alignment
  <bool> scrollable_x
  <bool> scrollable_y
  <uint16> num_children
  <uint32> widget_size
  <widget>
  (<uint32> widget_size
   <widget>
   ...)
  ```

- array_dynamic