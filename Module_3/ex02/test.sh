#!/bin/bash

if [ -z "$1" ]; then
  echo "Uso: add_getset include/ficheiro.hpp"
  exit 1
fi

HPP_FILE=$1

if [ ! -f "$HPP_FILE" ]; then
  echo "Erro: $HPP_FILE não existe"
  exit 1
fi

# Nome base (pessoa.hpp → pessoa)
BASE_NAME=$(basename "$HPP_FILE" .hpp)

CPP_FILE="src/${BASE_NAME}.cpp"

# Nome da classe
CLASS_NAME=$(grep -E "class " "$HPP_FILE" | head -n1 | awk '{print $2}')

GETTERS_SETTERS_H=""
GETTERS_SETTERS_CPP=""

# Extrair atributos privados
ATTRIBUTES=$(awk '
/private:/ {flag=1; next}
/public:/ {flag=0}
flag && /;/ {
    gsub(";", "")
    print
}
' "$HPP_FILE")

while IFS= read -r line; do
    TYPE=$(echo "$line" | awk '{print $1}')
    NAME=$(echo "$line" | awk '{print $2}')

    # remover underscore
    CLEAN_NAME=${NAME#_}

    # Capitalizar
    CAP="$(tr '[:lower:]' '[:upper:]' <<< ${CLEAN_NAME:0:1})${CLEAN_NAME:1}"

    # Melhor prática string
    if [ "$TYPE" = "std::string" ]; then
        SET_TYPE="const std::string&"
    else
        SET_TYPE="$TYPE"
    fi

    # HPP
    GETTERS_SETTERS_H+="    $TYPE get$CAP() const;\n"
    GETTERS_SETTERS_H+="    void set$CAP($SET_TYPE $CLEAN_NAME);\n\n"

    # CPP
    GETTERS_SETTERS_CPP+="$TYPE $CLASS_NAME::get$CAP() const {\n"
    GETTERS_SETTERS_CPP+="    return $NAME;\n}\n\n"

    GETTERS_SETTERS_CPP+="void $CLASS_NAME::set$CAP($SET_TYPE $CLEAN_NAME) {\n"
    GETTERS_SETTERS_CPP+="    this->$NAME = $CLEAN_NAME;\n}\n\n"

done <<< "$ATTRIBUTES"

# Inserir no HPP antes de private:
sed -i "/private:/i\\
$GETTERS_SETTERS_H
" "$HPP_FILE"

# Criar CPP se não existir
if [ ! -f "$CPP_FILE" ]; then
    echo "#include \"${BASE_NAME}.hpp\"" > "$CPP_FILE"
fi

# Adicionar implementações ao CPP
echo -e "\n$GETTERS_SETTERS_CPP" >> "$CPP_FILE"

echo "✔ Getters/Setters adicionados!"
echo "✔ Atualizado: $HPP_FILE"
echo "✔ Atualizado: $CPP_FILE"