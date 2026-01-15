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
    alignment: (left | right | center | fill),
    keep_grid: <bool>,
    reflow_direction: (horizontal | vertical),
    max_reflow_sections: <int> # 0 for no limit
    num_children: <int>,
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
