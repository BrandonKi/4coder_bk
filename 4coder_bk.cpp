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


CUSTOM_COMMAND_SIG(bk_move_right_word_boundary)
CUSTOM_DOC("Seek right for boundary between word characters and non-word characters.")
{
    Scratch_Block scratch(app);
    current_view_scan_move(app, Scan_Forward, push_boundary_list(scratch, boundary_alpha_numeric_underscore_utf8));
}

CUSTOM_COMMAND_SIG(bk_move_left_word_boundary)
CUSTOM_DOC("Seek left for boundary between word characters and non-word characters.")
{
    Scratch_Block scratch(app);
    current_view_scan_move(app, Scan_Backward, push_boundary_list(scratch, boundary_alpha_numeric_underscore_utf8));
}