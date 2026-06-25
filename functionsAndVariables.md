# Technical Design Document: PC Component & Assembly Invoice Management System

This document outlines the architectural design, data structures, and function signatures for the PRF192 project. 

---

## 1. Data Models & System Structures

### 1.1 `struct pcComponent`
Represents an individual hardware component in inventory.

| Field Name | Data Type | Constraints / Description |
| :--- | :--- | :--- |
| `id` | `int` | Global unique identifier (Auto-incrementing) |
| `category` | `char[20]` | Hardware type: `Mainboard`, `PSU`, `CPU`, `GPU`, `RAM`, `SSD`, `Case` |
| `name` | `char[50]` | Brand name and model specification |
| `socket` | `char[20]` | CPU/Mainboard connection type (e.g., `AM5`, `LGA1700`) |
| `ddr` | `char[10]` | RAM/Mainboard memory generation (e.g., `DDR4`, `DDR5`) |
| `warrantyPeriod`| `int` | Warranty duration specified in months |
| `stock` | `int` | Current quantity available in inventory ($\ge 0$) |

### 1.2 `struct componentManage`
The central warehouse inventory database.

| Field Name | Data Type | Constraints / Description |
| :--- | :--- | :--- |
| `components` | `struct pcComponent[1000]` | Array storing tracking data for up to 1000 items |
| `count` | `int` | Total number of unique components currently registered |

### 1.3 `struct pcInvoice`
Represents a customer's specific custom PC build configuration order.

| Field Name | Data Type | Constraints / Description |
| :--- | :--- | :--- |
| `id` | `int` | Unique tracking invoice identifier (Auto-incrementing) |
| `componentId` | `int[20]` | Array tracking IDs of components chosen for this build |
| `componentCount`| `int` | Total quantity of components included in this invoice ($\le 20$) |
| `assemblyStatus`| `int` | Status flags: `0` (Pending), `1` (Assembling), `2` (Completed) |

### 1.4 `struct invoiceManage`
The master ledger tracking all customer configurations.

| Field Name | Data Type | Constraints / Description |
| :--- | :--- | :--- |
| `invoices` | `struct pcInvoice[1000]` | Array tracking system builds for up to 1000 customers |
| `count` | `int` | Total number of invoices stored in active memory |

---

## 2. API Reference & Function Prototypes

### 2.1 Inventory Management Modules (`component_`)

#### `void component_add(struct componentManage *cM)`

* **Description:** Prompts user interface inputs to register a new component into the warehouse array. Automatically assigns a global unique `id`.

#### `int component_update_stock(struct componentManage *cM, int id, int newStock)`

* **Description:** Direct mutation module to adjust inventory metrics.
* **Returns:** `1` if the update is successful, `0` if the target `id` is invalid.

#### `struct pcComponent* component_search_by_id(const struct componentManage *cM, int id)`

* **Description:** Scans memory vectors using a binary or linear search pattern matching the primary key.

* **Returns:** Pointer to the matching object instance; `NULL` if not found.

#### `void component_search_menu(const struct componentManage *cM)`

* **Description:** Renders the user console terminal options for filtering inventory records (e.g., by exact Name substring or Category).

#### `void component_track_stock(const struct componentManage *cM)`

* **Description:** Generates critical low-stock warning reports for logistics review.

#### `void component_show_all(const struct componentManage *cM)`

* **Description:** Iteratively prints every item in the warehouse system utilizing the `component_show` module.

#### `void component_show(const struct pcComponent *pcC)`

* **Description:** Low-level console rendering utility to print a clean data block of a single component.

#### `int component_delete(struct componentManage *cM, int id)`

* **Description:** Removes a component from active registers by index manipulation and decrements database array counts.

* **Returns:** `1` on complete success, `0` if deletion protocols abort.

---

### 2.2 Assembly & Order Modules (`invoice_`)

#### `void invoice_add(struct invoiceManage *iM, struct componentManage *cM)`

* **Description:** Launches custom PC builder order initialization pipelines, prompting users for components to add to their queue.

#### `int invoice_check_valid_compatibility(const struct pcInvoice *invoice, const struct componentManage *cM)`

* **Description:** Validation engine evaluating dependencies between the assigned parts of an open invoice. Evaluates RAM-to-Mainboard (`ddr`) and CPU-to-Mainboard (`socket`) attributes using internal flags.

* **Returns:** `1` if all components match successfully, `0` if a mismatch is flagged.

#### `void invoice_sort_assembly_status(struct invoiceManage *iM)`

* **Description:** Sorts order indexes chronologically or hierarchically grouped by their `assemblyStatus` values.

#### `void invoice_show_all(const struct invoiceManage *iM, const struct componentManage *cM)`

* **Description:** Iteratively lists system invoices. Leverages low-level printing wrappers to cross-reference IDs against live names.

#### `void invoice_track_and_update_assembly_status(struct invoiceManage *iM)`

* **Description:** State modification pipeline moving an order along processing tracks (e.g., advancing from `Assembling` to `Completed`).

#### `int invoice_delete(struct invoiceManage *iM, int id)`

* **Description:** Drops canceled builds from active buffers.

---

## 3. Application Control Flow Architecture

```text
Main Application Loop [main.c]
├── 1. Inventory Database Console [Component Menu]
│   ├── component_add()
│   ├── component_update_stock() -> [Calls component_searchById()]
│   ├── component_search_menu()
│   │   ├── Option A: Search by Name Substring
│   │   └── Option B: Search by Target ID Primary Key
│   ├── component_track_stock()  -> [Calls component_show_all()]
│   ├── component_update_info()   -> [Calls component_search_by_id()]
│   └── component_delete()      -> [Removes entry & shifts array pointers]
│
└── 2. Build Configuration Console [Invoice Menu]
    ├── invoice_add()
    ├── invoice_check_valid_compatibility()
    │   ├── component_is_socket_compatible()
    │   └── component_is_ddr_compatible()
    ├── invoice_sort_assembly_status()
    ├── invoice_track_and_update_assembly_status()
    └── invoice_delete()
