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
  }, #optional, default {"", "", "", "", "", ""}
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
    title: <string>, #optional, default ""
    size_x: <int>, #optional, default 0, 0 for dynamic calculation
    size_y: <int>, #optional, default 0, 0 for dynamic calculation
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
    alignment: (left | right | center | fill), #optional, default fill
    scrollable_x: <bool>, #optional, default true
    scrollable_y: <bool>, #optional, default true
    w_children: [
      <widget>,
      ...
    ]
  }
  ```

- Dynamic array
  ```
  <widget>: array_dynamic {
    id: <string>,
    alignment: (left | right | center | fill), #optional, default fill
    keep_grid: <bool>, #optional, default false
    reflow_direction: (horizontal | vertical), #optional, default horizontal
    max_reflow_sections: <int> #optional, default 0, 0 for no limit
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
    label: <string>, #optional, default ""
    label_align_x: (left | center | right), #optional, default center
    label_align_y: (top | center | bottom), #optional, default center
    size_min_x: <int>, #optional, default 0, 0 for no limit
    size_min_y: <int>, #optional, default 0, 0 for no limit
    size_max_x: <int>, #optional, default 0, 0 for no limit
    size_max_y: <int>, #optional, default 0, 0 for no limit
    callback_id_press: <string>, #optional, default ""
  }
  ```

- Checkbox
  ```
  <widget>: checkbox {
    id: <string>,
    label: <string>, #optional, default ""
    checked: <bool>, #optional, default false
    callback_id_check: <string>, #optional, default ""
    callback_id_uncheck: <string>, #optional, default ""
  }
  ```

- Container
  ```
  <widget>: container {
    id: <string>,
    padding_relative_l: <float>, #optional, default 0.0
    padding_relative_r: <float>, #optional, default 0.0
    padding_relative_t: <float>, #optional, default 0.0
    padding_relative_b: <float>, #optional, default 0.0
    padding_absolute_l: <int>, #optional, default 0
    padding_absolute_r: <int>, #optional, default 0
    padding_absolute_t: <int>, #optional, default 0
    padding_absolute_b: <int>, #optional, default 0
    w_child: <widget>
  }
  ```

- Labeled container
  ```
  <widget>: container_label {
    id: <string>,
    label: <string>, #optional, default ""
    label_align: (left | center | right), #optional, default center
    border <bool>, #optional, default false
    w_child: <widget>
  }
  ```

> TODO: finish writing this i guess
