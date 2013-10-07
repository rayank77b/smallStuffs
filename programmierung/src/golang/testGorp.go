package main

import (
    "reflect"
    "fmt"
    "bytes"
)

type DbMap struct {
    Db           string
    tables       []*TableMap
}

type TableMap struct {
    gotype      reflect.Type
    Name        string
    Columns     []*ColumnMap
}

type ColumnMap struct {
    gotype      reflect.Type
    Name        string
    SqlType     string
}

func (m *DbMap) AddTable(i interface{}) *TableMap {
    t := reflect.TypeOf(i)
    tmap := &TableMap{gotype: t, Name: t.Name() }

    n := t.NumField()
    tmap.Columns = make([]*ColumnMap, n, n)
    for i := 0; i < n; i++ {
        f := t.Field(i)
        tmap.Columns[i] = &ColumnMap{
            gotype : f.Type, 
            Name : f.Name, 
            SqlType : ValueToSqlType(f.Type),
        }
    }
    n = len(m.tables)
    if (n+1) > cap(m.tables) { 
        newArr := make([]*TableMap, n, 2*(n+1))
        copy(newArr, m.tables)
        m.tables = newArr
    } 
    m.tables = m.tables[0 : n+1]
    m.tables[n] = tmap
    return tmap
}
func (m *DbMap) CreateTables() error {
    var err error
    for i := range m.tables {
        buffer := bytes.NewBufferString("");
        table := m.tables[i]
        fmt.Fprintf(buffer, "create table %s (\n", table.Name)
        for x := range table.Columns {
            col := table.Columns[x]
            if x > 0 {
                fmt.Fprint(buffer, ", ")
            }
            fmt.Fprintf(buffer, "    %s %s\n", col.Name, col.SqlType)
        }
        fmt.Fprintf(buffer, ");")
        fmt.Println("Create Tables:")
        fmt.Println("buffer: ", buffer)
    }
    return err
}

func (m *DbMap) DropTables() error {
    var err error
    for i := range m.tables {
        table := m.tables[i]
        fmt.Println("DropTables: ", fmt.Sprintf("drop table %s;", table.Name))
    }
    return err
}

func (m *DbMap) Put(i interface{})  {
    table := m.TableFor(reflect.TypeOf(i))
    args := make([]interface{}, len(table.Columns))
    buffer := bytes.NewBufferString("")
    fmt.Fprintf(buffer, "insert into %s (", table.Name)
	v := reflect.ValueOf(i)
    for x := range table.Columns {
        col := table.Columns[x]
        if x > 0 {
            fmt.Fprint(buffer, ", ")
        }
        fmt.Fprint(buffer, col.Name)
		fmt.Printf("  Put()  col.Name=%s col.gotype=%v\n", col.Name, col.gotype)
        args[x] = v.FieldByName(col.Name).Interface()
    }
    fmt.Fprint(buffer, ") values (")
    for x := range table.Columns {
        if x > 0 {
            fmt.Fprint(buffer, ", ")
        }
        fmt.Fprint(buffer, "?")
    }
    fmt.Fprint(buffer, ");")
	fmt.Printf(" sql: %s %v\n", buffer.String(), args)
    fmt.Println(buffer.String())
}


/////////////

func (m *DbMap) TableFor(t reflect.Type) *TableMap {
    for i := range m.tables {
        table := m.tables[i]
        if (table.gotype == t) {
            return table
        }
    }
    panic(fmt.Sprintf("No table found for type: %v", t.Name()))
}

func ValueToSqlType(val reflect.Type) string {
    switch (val.Kind()) {
    case reflect.Int, reflect.Int16, reflect.Int32:
        return "int"
    case reflect.Int64:
        return "bigint"
    }

    return "varchar(255)"
}

// ###########################################################################
type Invoice struct {
    Id          int64
    Created     int64
    Updated     int64
}

func main() {
    inv := Invoice{Id: 99, Created: 100, Updated: 200}
    dbmap := &DbMap{}

     t1 := dbmap.AddTable(Invoice{})
    t1.Name = "invoice_test"

    dbmap.Db = "DB"
    dbmap.CreateTables()
    dbmap.DropTables()
    dbmap.Put(inv)
}

