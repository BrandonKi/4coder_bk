CUSTOM_COMMAND_SIG(indent_with_space)
CUSTOM_DOC("insert spaces instead of tab character")
{
	View_ID view = get_active_view(app, Access_Always);
    Buffer_ID buffer = view_get_buffer(app, view, Access_Always);
    
    if (buffer_get_access_flags(app, buffer) & Access_Write)
	{
		write_text(app, string_u8_litexpr("    "));
    }
    else
	{
        goto_jump_at_cursor(app);
    }
}