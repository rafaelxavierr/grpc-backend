# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# NO CHECKED-IN PROTOBUF GENCODE
# source: dictionary.proto
# Protobuf Python Version: 5.29.0
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import runtime_version as _runtime_version
from google.protobuf import symbol_database as _symbol_database
from google.protobuf.internal import builder as _builder
_runtime_version.ValidateProtobufRuntimeVersion(
    _runtime_version.Domain.PUBLIC,
    5,
    29,
    0,
    '',
    'dictionary.proto'
)
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x10\x64ictionary.proto\"\x1b\n\x0bWordRequest\x12\x0c\n\x04word\x18\x01 \x01(\t\"\x1f\n\x0cWordResponse\x12\x0f\n\x07message\x18\x01 \x01(\t\"#\n\x04Word\x12\x0c\n\x04word\x18\x01 \x01(\t\x12\r\n\x05\x63ount\x18\x02 \x01(\x05\" \n\x08WordList\x12\x14\n\x05words\x18\x01 \x03(\x0b\x32\x05.Word\"\x07\n\x05\x45mpty2]\n\x11\x44ictionaryService\x12&\n\x07\x41\x64\x64Word\x12\x0c.WordRequest\x1a\r.WordResponse\x12 \n\x0bGetAllWords\x12\x06.Empty\x1a\t.WordListb\x06proto3')

_globals = globals()
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, _globals)
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'dictionary_pb2', _globals)
if not _descriptor._USE_C_DESCRIPTORS:
  DESCRIPTOR._loaded_options = None
  _globals['_WORDREQUEST']._serialized_start=20
  _globals['_WORDREQUEST']._serialized_end=47
  _globals['_WORDRESPONSE']._serialized_start=49
  _globals['_WORDRESPONSE']._serialized_end=80
  _globals['_WORD']._serialized_start=82
  _globals['_WORD']._serialized_end=117
  _globals['_WORDLIST']._serialized_start=119
  _globals['_WORDLIST']._serialized_end=151
  _globals['_EMPTY']._serialized_start=153
  _globals['_EMPTY']._serialized_end=160
  _globals['_DICTIONARYSERVICE']._serialized_start=162
  _globals['_DICTIONARYSERVICE']._serialized_end=255
# @@protoc_insertion_point(module_scope)
